#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int elem;
    Node *next;
}*head=NULL,*tail=NULL;

Node* createnode(int x)
{
    Node *temp=new Node;
    temp->elem=x;
    temp->next=NULL;
    return temp;
}
void insertfromend(Node* insert)
{
    if(head==NULL)
    {
      head=tail=insert;
      
    }
    else
    {
       tail->next = insert;
       tail = insert;

    }
}
void traverse()
{
    Node *temp=head;
    cout<<"\n";
    while(temp!=NULL)
    {
        cout<<temp->elem<<"->";
        temp=temp->next;
    }
}
void solve()
{
    int n,x,check,freq=0;
    cout<<"Enter the no. of elements in Linked List\n";
    cin>>n;
    cout<<"Enter elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>x;
        insertfromend(createnode(x));

    }
   cout<<"Enter the element to be checked and deleted for\n";
   cin>>check;
   Node *temp = head,*prev=NULL;
   while(temp!=NULL && temp->elem==check)
   {   freq++;
       head = temp->next;
       delete temp;
       temp=head;
   }
   while(temp!=NULL)
   {
     while(temp!=NULL && temp->elem!=check)
     {
         prev=temp;
         temp=temp->next;
     }
     if(temp==NULL)
     break;
     
     freq++;
     prev->next = temp->next;
     delete temp;
     temp=prev->next;
   }
   cout<<"Frequency of element "<<check<<" is "<<freq<<"\n";
   cout<<"New Linked list is \n";
   traverse();
}
int main()
{

solve();
return 0;
}
