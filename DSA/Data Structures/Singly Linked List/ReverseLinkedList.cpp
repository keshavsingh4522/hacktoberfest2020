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
void reverselinkedlist()
{
    Node *prev=NULL,*curr=head,*next=NULL;
    while(curr!=NULL)
    {   next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        
    }
    head = prev;
}

void traverse()
{
    Node *ptr = head;
    while(ptr!=NULL)
    {
        cout<<ptr->elem<<"->";
        ptr = ptr->next;
    }
}
int main()
{
int n,x;
cout<<"Enter the Number of Nodes in the Linked List\n";
cin>>n;
cout<<"Enter the Elements of Linked List\n";
for(int i=0;i<n;i++)
{
    cin>>x;
    insertfromend(createNode(x));

}
cout<<"Reversed Linked List becomes\n";
reverselinkedlist();
traverse();
return 0;
}
