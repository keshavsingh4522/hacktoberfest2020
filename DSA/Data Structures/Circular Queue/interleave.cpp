#include<iostream>
using namespace std;
struct Node 
{
    int elem;
    Node* next;
};
Node* createNewNode(int x)
{
    Node* temp = new Node();
    temp->elem = x;
    temp->next = NULL;
    return temp;
}
class Queue{
         private:
         Node *head = NULL,*tail = NULL;
         int size;

         public:
        Queue(int size)
         {
              
               this->size = 0;
         }
        
         void enqueue(int x)
         {    
             Node* insert = createNewNode(x);
             if(head == NULL)
                 head = tail = insert;
              else
              {
                 tail->next = insert;
                 tail = insert;
              }
         }
         void dequeue()
         {
             if(head==NULL)
             cout<<"Underflow";
             else
             {
                 Node* temp = head;
                 head = head->next;
                 delete temp;
             }
         }
         void display()
         {
             Node* temp = head;
             while(temp!=NULL)
             {
                 cout<<temp->elem<<" ";
                 temp = temp->next;
             }
         }

         int peek()
         {
            if(head!=NULL)
            return head->elem;
            
            return -1;
         }


};
class Stack{
    Node* head=NULL;
    int size;
    
    public:
    
    Stack(int x)
    {  
        this->size = x;
    }
    
void push(int elem)
{
        Node *insert = createNewNode(elem);
     if(head == NULL)
     head =insert;
     else
     {
        insert->next = head;
        head = insert;
     }
     
 }   
void pop()
{ 
        if(head==NULL)
        cout<<"Undeflow!!\n";
        else
        {
              Node *del=head;
              head = head->next;
              delete(del);
               
        }
      
}
int top()
{
    if(head!=NULL)
    return head->elem;

    return -1;
}
void traverse()
{
    Node* temp = head;
    while(temp!=NULL)
    {
    cout<<temp->elem<<" ";
    temp = temp->next;
    }
    cout<<"\n";
}
};
int main()
{
  int n,elem;
  cout<<"Enter Number of Elements in the queue: ";
  cin>>n;
  Queue a(n);
  Stack b(n);
  cout<<"\nEnter Elements of the queue: ";
  for(int i = 0;i<n;i++)
  {
      cin>>elem;
      a.enqueue(elem);
      
  }
  for(int i=0;i<n/2;i++)
  {
      b.push(a.peek());
      a.dequeue();
  }
  while(b.top()!=-1)
  {
      a.enqueue(b.top());
    b.pop();
  }
  for(int i = 0;i<n/2;i++)
  {
      a.enqueue(a.peek());
      a.dequeue();
  }
  for(int i = 0;i<n/2;i++)
  {
      b.push(a.peek());
      a.dequeue();
  }
 for(int i = 0;i<n;i++)
 {
     if(i%2==0)
     {
         a.enqueue(b.top());
         b.pop();
     }
     else
     {
         a.enqueue(a.peek());
         a.dequeue();
     }
 }
 cout<<"Interleaved elements are: ";
 a.display();

}