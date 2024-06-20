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
void reverse(int m,int n)
  {
    if(head==NULL)
    {
       cout<<"Empty"<<endl;
    }
    else{
       Node *prev=NULL;
    Node *ptr=head;
    while(m>1)
    {
       prev=ptr;
       ptr=ptr->next;
       m--;
       n--;
    }
    Node *conn=prev;
    Node *tail=ptr;
    while(n>0)
    {
      Node *next_Node=ptr->next;
      ptr->next=prev;
      prev=ptr;
      ptr=next_Node;
      n--;
    }
    if(conn!=NULL)
    {
      conn->next=prev;
    }
    else
       head=prev;

       tail->next=ptr;

    }

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
int n,x,first,last;
cout<<"Enter the Number of Nodes in the Linked List\n";
cin>>n;
cout<<"Enter the Elements of Linked List\n";
for(int i=0;i<n;i++)
{
    cin>>x;
    insertfromend(createNode(x));

}
cout<<"Enter first and last index\n";
cin>>first>>last;
reverse(first,last);
traverse();
return 0;
}
