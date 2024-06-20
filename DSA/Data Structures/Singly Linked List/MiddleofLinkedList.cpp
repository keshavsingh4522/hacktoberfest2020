#include<iostream>
using namespace std;
struct Node
{
    int elem;
    Node *next;
}*head =NULL,*tail = NULL;
Node* createNode(int x)
{
    Node *ptr = new Node();
    ptr->elem = x;
    ptr->next = NULL;
    return ptr;
    
}
void insertfromend(Node *insert)
{
   if(head==NULL)
       head = tail = insert;
   
   else
   {
       tail->next = insert;
       tail = insert;
   }
}
int findmiddle()
{
    Node *fast=head,*superfast=head;
    while(superfast->next!=NULL )
    {
        fast = fast->next;
        superfast = superfast->next->next;
    }
    return fast->elem;
}
int main()
{
int n,x;
cout<<"Enter the Number of Nodes in the Linked List(Take Elements odd to get correct output)\n";
cin>>n;
cout<<"Enter the Elements of Linked List\n";
for(int i=0;i<n;i++)
{
    cin>>x;
    insertfromend(createNode(x));

}
cout<<"The Middle of Linked List is "<<findmiddle()<<" ";
return 0;
}
