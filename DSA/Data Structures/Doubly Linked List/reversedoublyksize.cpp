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

void insertfromend(Node *insert)
{
   if(tail==NULL)
   head = tail = insert;
   else
   {
       tail->next = insert;
       insert->prev = tail;
       tail = insert;
   }
}
void reverseksize(int k )
{
     Node *start=head,*end,*temp=head;
     int index =1;

     while(temp!=NULL)
     {    
         if(index%k==0)
         {
            end = temp;
            while(start<end)
            {
                swap(start->elem,end->elem);
                start = start->next;
                end = end->prev;
            }
            start = temp->next;
         }
         temp = temp->next;
         index++;
     }
     if((index-1)%k!=0)
     {
          end = tail;
            while(start<end)
            {  
                swap(start->elem,end->elem);
                start = start->next;
                end = end->prev;
            }
     }
  
}
void traverse()
{
    Node* ptr = head;
    while(ptr!=NULL)
    {
        cout<<ptr->elem<<"<->";
        ptr = ptr->next;
    }
}

int main()
{  
  int n,elem,k;
  cout<<"Enter no. of elements of Doubly Linked List\n";
  cin>>n;
  cout<<"Enter Elements of Doubly Linked List\n";
  for(int i = 0;i<n;i++)
  {
      cin>>elem;
      insertfromend(createNode(elem));
  }
  cout<<"Enter Number of Groups for reversal\n";
  cin>>k;
  cout<<"Doubly Linked List looks like:\n";
  reverseksize(k);
  traverse();
return 0;
}
