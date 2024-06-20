#include<iostream>
using namespace std;
struct Node
{
    int elem;
    Node *next,*prev;
}*head=NULL,*tail=NULL;
Node* createNode(int x)
{
    Node* temp = new Node();
    temp->elem = x;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void insertfrombeg(Node* insert)
{
    if(head==NULL)
    head = tail = insert;
    else
    {
        insert->next = head;
        head->prev = insert;
        head = insert;

    }
}
void findsize()
{
    Node* ptr = head;
    int count = 0;
    while(ptr!=NULL)
    { 
        ptr = ptr->next;
        count++;

    }
    cout<<"Size of Doubly Linked List is: "<<count;
}
int main()
{

// Creating a Random Linked List with some Elements
for(int i=0;i<=5;i++)
{
insertfrombeg(createNode(i));
}
findsize();

return 0;
}
