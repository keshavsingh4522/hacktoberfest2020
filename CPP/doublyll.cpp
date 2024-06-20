#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {

        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node()
    {
        // memory free
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->prev = NULL;
            this->next = NULL;
        }
        cout << "memory freed for the node with data " << value << endl;
    }
};
void deletenode(Node *&head, int pos, Node *&tail)
{
    if (pos == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prevv = NULL; // here we changed the name to
        // prevv so that doesnt conflict with our Node pointers declaration.
        int cnt = 1;
        while (cnt < pos)
        {
            prevv = curr;
            curr = curr->next;
            cnt++;
        }
        curr->prev = NULL;

        if (curr->next == NULL)
        {
            prevv->next = NULL; // We did this extra part here to ensure
            // that tail properly deletes and gets freed from the memory

            tail = prevv; // this part added in order to update the
            // tail according to new deletions.
            delete curr;
            return;
        }
        prevv->next = curr->next;

        curr->next->prev = prevv;

        curr->next = NULL; // Very important step as even after deletion it was still
        // pointing to the next node so better do its next to NULL then delete it.
        delete curr;
        return;
    }
}
void insertathead(Node *&head, int d)
{
    // We can also include a case where head and tail both are NULL from the start and
    // directly we are trying to insert at the head L-44 Love Babbar
    Node *temp = new Node(d);
    head->prev = temp;
    temp->next = head;
    temp->prev = NULL;
    head = temp;
}
void insertattail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    // temp->next=NULL not needed as we already have done it in our constructor
    tail->next = temp;
    temp->prev = tail;

    tail = temp; // in short temp ko hi point krlia taki tail hamara ab temp bn jaye as end me vhi hai abhi currently
}

void insertatpos(Node *&tail, Node *&head, int d, int pos)
{
    int cnt = 1;
    Node *temp = new Node(d);
    Node *pnt = head;
    if (pos == 1)
    {
        insertathead(head, d);
        return; // so that repetetion doesnt happen and uniquely gets placed
    }

    while (cnt < pos - 1)
    {

        pnt = pnt->next; // we are just moving forward with its help

        cnt++;
    }
    if (pnt->next == NULL)
    {
        // this means that this element will be inserted at the end so needs to be declared tail
        insertattail(tail, d);
        return;
    }
    temp->next = pnt->next;
    pnt->next->prev = temp;
    temp->prev = pnt;
    pnt->next = temp;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int getlength(Node *&head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    cout << "Length " << cnt << endl;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    insertathead(head, 110);
    print(head);
    getlength(head);
    insertattail(tail, 255);
    print(head);
    getlength(head);
    insertatpos(tail, head, 65, 2);
    insertatpos(tail, head, 157, 2);
    insertatpos(tail, head, 1597, 2);
    print(head);
    deletenode(head, 6, tail);
    cout << endl;
    print(head);
}