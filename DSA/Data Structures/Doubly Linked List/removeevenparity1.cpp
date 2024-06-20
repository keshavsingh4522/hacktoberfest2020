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

void traverse()
{
    Node* ptr = head;
    while(ptr!=NULL)
    {
        cout<<ptr->elem<<"<->";
        ptr = ptr->next;
    }
}
bool checkparity(int n)
{
    int count_one = 0;
    while(n!=0)
    {
        if(n%2)
        count_one++;
        n/=2;
    }
    return count_one%2==0;
}
void removeevenparity()
{
    Node* temp = head;
    while(temp!=NULL)
    {
        if(checkparity(temp->elem))
      {  
           Node* del=temp;
          if(temp==head)
          {
              head = head->next;
              temp = temp->next;
          }
          else if(temp==tail)
          {
            tail = tail->prev;   
          }
         else{ 
             temp->prev->next = temp->next;
          temp->next->prev = temp->prev;
          temp = temp->next;
         
         }
         delete(del);
      }
      else
        temp = temp->next;
    }
}

int main()
{  
   int n,elem;
   cout<<"Enter Number of Elements in Linked List:\n";
   cin>>n;
   cout<<"Enter Elements in Linked List:\n";
   for(int i = 0;i<n;i++)
   {
       cin>>elem;
       insertfromend(createNode(elem));
   }
   removeevenparity();
   cout<<"Linked List after removing Even Parity Elements is\n";
   traverse();

return 0;
}
