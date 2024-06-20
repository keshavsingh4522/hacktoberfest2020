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
int deletefreq(int x)
{
    int freq = 0;
    Node *ptr = head,*temp,*prev = NULL;
    while(ptr!=NULL && ptr->elem == x)
    { 
       temp = ptr;
       ptr = ptr->next;
       delete temp;  
       freq++;  
    }
    head = ptr;
    while(ptr!=NULL)
    {  
        if(ptr->elem == x)
        {   
            prev->next = ptr->next;
            delete ptr;
            ptr = prev;
            freq++;
        }
         prev = ptr;
       ptr = ptr->next;
    }
   return freq;
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
cout<<"Enter the Element to be deleted and checked\n";
cin>>x;
cout<<"The Frequency of the deleted Element is "<<deletefreq(x)<<"\n";
cout<<"The Linked List becomes\n";
traverse();
return 0;
}
