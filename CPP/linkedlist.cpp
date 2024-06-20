#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {

        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        // memory free
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
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
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        if (curr->next == NULL)
        {
            tail = prev; // this part added in order to update the
            // tail according to new deletions.
        }

        curr->next = NULL; // Very important step as even after deletion it was still
        // pointing to the next node so better do its next to NULL then delete it.
        delete curr;
        return;
    }
}
void insertathead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertattail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    // temp->next=NULL not needed as we already have done it in our constructor
    tail->next = temp;
    tail = tail->next; // in short temp ko hi point krlia taki tail hamara ab temp bn jaye as end me vhi hai abhi currently
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

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    cout << endl;
    insertathead(head, 12);
    insertathead(head, 11);
    insertathead(head, 10);
    insertathead(head, 9);
    print(head);
    insertattail(tail, 15);
    cout << endl;
    print(head);
    cout << endl;
    insertatpos(tail, head, 100, 1);
    print(head);
    deletenode(head, 1, tail);
    print(head);
    deletenode(head, 7, tail);
    print(head);
    insertattail(tail, 1555);
    print(tail);
}