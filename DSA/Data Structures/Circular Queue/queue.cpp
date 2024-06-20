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
         int capacity,size;

         public:
        Queue(int capacity)
         {
               this->capacity  = capacity;
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
              size++;
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
          size--;
         }
         bool isEmpty()
         {
             return head==NULL;
         }
         bool isFull()
         {
             return size==capacity;
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
int main()
{
       Queue s(100);
       int choice,x;
       while(true)
       {
          cout<<"\nQueue Menu Driven Program:\n1.Enqueue\n2.Dequeue\n3.IsEmpty?\n4.IsFull?\n5.Peek\n6.Display\n7.Exit\n";
          cin>>choice;
          switch(choice)
          {
              case 1:
              cout<<"\nEnter Element to be inserted\n";
              cin>>x;
              s.enqueue(x);
              break;

              case 2:
              cout<<"Deleting one Element\n";
              s.dequeue();
              break;

              case 3:
              if(s.isEmpty())
              cout<<"Queue is empty\n";
              else
              cout<<"Queue is not empty\n";
              break;

              case 4:
              if(s.isFull())
              cout<<"Queue is full\n";
              else
              cout<<"Queue is not full\n";
               break;

               case 5:
               if(s.peek()==-1)
               cout<<"Queue is Empty\n";
               else
               cout<<"Current elem is "<<s.peek()<<"\n";
               break;

               case 6 :
               cout<<"Queue looks like:\n";
               s.display();
               cout<<"\n";
               break;

               case 7 :
               cout<<"Exiting\n";
               exit(1);
               break;

               default: 
               cout<<"Wrong choice Entered\n";
               break;

          }
       }
}