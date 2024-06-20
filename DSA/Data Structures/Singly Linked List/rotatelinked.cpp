#include<iostream>
using namespace std;
struct Node
{
    int elem;
    Node* next;
}*head= NULL,*tail=NULL;
Node* createNode(int x)
{
    Node *ptr = new Node();
    ptr->elem = x;
    ptr->next = NULL;
    return ptr;
   
}
void insert(Node* insert)
{
    if(head==NULL)
    head = tail = insert;
    else
    {
        tail->next = insert;
        tail = insert;
    }
}
void traverse()
{
    Node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->elem<<"->";
        temp = temp->next;
    }
}
void rotate(int k)
{
    if(head==NULL )
    {cout<<"Linked List is Empty\n";
    return ;}
    
    Node *ptr=head,*temp;
    int index = 1;
    while(ptr->next!=NULL)
    {
         if(index== k)
        {
            temp = ptr;
        }
        ptr = ptr->next;
        index++;
       
    }
if(temp->next==NULL)
return ;
    ptr->next = head;
    head = temp->next;
    tail = temp;
    temp->next = NULL;

}
int main()
{
    
    int n,x,k;
    cout<<"Enter Number of Nodes\n";
    cin>>n;
    cout<<"Enter Nodes\n";
    for(int i=0;i<n;i++)
    {
        cin>>x;
        insert(createNode(x));
    }
    cout<<"Enter Rotation Factor\n";
    cin>>k;
    rotate(k);
   traverse();
}