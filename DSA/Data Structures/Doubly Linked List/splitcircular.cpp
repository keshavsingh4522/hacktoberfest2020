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
void splitcircular()
{
    Node *mid,*temp;
    temp = mid = head;
    if(temp==NULL) 
    {cout<<"Linked List empty!!! Pls check again";
    return ;}

    do{
     temp = temp->next->next;
     mid = mid->next;


    }while(temp!=head && temp!=head->next);
   cout<<"First Part of the Circular Linked List:\n";
 temp = head;
 while(temp!=mid)
 {
     cout<<temp->elem<<" ";
     temp = temp->next;

 }
 cout<<"\nSecond Part of the Linked List:\n";
 while(temp!=head)
 {
     cout<<temp->elem<<" ";
     temp = temp->next;
 }
}
int main()
{

const int n = 5;
for(int i=0;i<n;i++)
{
insert(createNode(i));
}
splitcircular();
return 0;
}
