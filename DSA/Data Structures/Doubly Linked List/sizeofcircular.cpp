#include<iostream>
using namespace std;
struct Node
{
    int elem;
    Node* next;
}*head=NULL,*tail=NULL;
Node* createNode(int x)
{
    Node* temp = new Node();
    temp->elem = x;
    temp->next = NULL;
    return temp;
}
void insert(Node* insert)
{
    if(head == NULL)
    {
        head = tail = insert;
        head->next = head;
    }
    else
    {
        insert->next = tail->next;
        tail->next = insert;
        tail = insert;
    }
}
int sizeofCircular()
{
    if(head==NULL)
    return 0;
    Node *ptr = head;
    int count = 0;
    do
    {
        ptr = ptr->next;
        count++;

    }while(ptr!=head && ptr!=NULL);
return count;
}
int main()
{

const int n = 5;
for(int i=0;i<n;i++)
{
insert(createNode(i));
}
cout<<"Size of Circular Linked List is \n"<<sizeofCircular();

return 0;
}
