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
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory freed for the node with data " << value << endl;
    }
};
void deletenode(Node *&tail, int value)
{
    if (tail == NULL)
    {
        cout << "Circular LL is empty " << endl;
        return;
    }
    else
    {
        Node *prev = tail;
        Node *curr = prev->next;
        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if (curr == prev)
        {
            tail = NULL; // when only one node exists then after deletion
            // tail must be set NULL so that no memory error comes. 
        }
        if (curr == tail)
        {
            tail = prev; // for the case where tail element is being
            // deleted there we should update the tail;
        }

        curr->next = NULL;

        delete curr;
    }
}
void insertnode(Node *&tail, int element, int d)
{
    if (tail == NULL)
    {
        Node *newnode = new Node(d);
        tail = newnode;
        tail->next = newnode; // pointing to itself as it is a circular ll
    }
    else
    {
        Node *temp = new Node(d);
        Node *curr = tail;
        while (curr->data != element)
        {

            curr = curr->next;
        }
        // element found
        temp->next = curr->next;
        curr->next = temp;
    }
}
void print(Node *&tail)
{
    Node *temp = tail;
    // cout << temp->data << endl;
    // while (tail->next != temp)//this condition wont run when only single node is there
    // //so we need to print single first node seperately.
    // {
    //     cout << tail->data << " ";
    //     tail = tail->next;
    // }
    // cout << endl;
    if (tail == NULL)
    {
        cout << "Circular LL is empty." << endl;
    }
    do
    {
        cout << tail->data << " ";
        tail = tail->next;

    } while (tail != temp);
}
int main()
{
    Node *tail = NULL;
    insertnode(tail, 5, 3);
    insertnode(tail, 3, 4);
    insertnode(tail, 4, 8);
    insertnode(tail, 8, 6);
    insertnode(tail, 6, 7);
    deletenode(tail, 6);
    print(tail);
}