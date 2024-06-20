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
void insertfromend(Node* insert)
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
void traverse()
{
   if(head==NULL)
   return ;
    Node* ptr = head;
    do
    {   cout<<ptr->elem<<"->";
        ptr = ptr->next;
    }while(ptr!=head && ptr!=NULL);
    if(ptr!=NULL)
    cout<<ptr->elem;
}
int main()
{

int n,x;
cout<<"Enter the number of Nodes in Circular Linked List\n";
cin>>n;
cout<<"Enter the elements of the Linked List\n";
for(int i=0;i<n;i++)
{
cin>>x;
insertfromend(createNode(x));
}
traverse();

return 0;
}
