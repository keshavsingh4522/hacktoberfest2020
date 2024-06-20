#include<iostream>
#include<climits>
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
        

         public:
          int size;
        Queue(int size)
         {
              
               this->size = size;
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
int main()
{
    int n,elem,min_index,minimum,tracker;
    cout<<"Enter no of elements in the Queue: ";
    cin>>n;
    Queue a(n);
    cout<<"Enter Elements: ";
    for(int i = 0;i<n;i++)
    {
     cin>>elem;
     a.enqueue(elem);
    }
   while(n--)
   {
       minimum = INT_MAX;
       for(int i = 0;i<a.size;i++)
       {
           if(minimum>a.peek() && i<=n)
           {
                 minimum = a.peek();
                 min_index = i;
           }
           a.enqueue(a.peek());
           a.dequeue();
       }
       for(int i = 0;i<a.size;i++)
       {
           if(i!=min_index)
           {
            a.enqueue(a.peek());
           a.dequeue();
           }
           else 
           {
               a.dequeue();
           }
       }
         
      a.enqueue(minimum);
    

   }
    cout<<"Sorted Queue is: ";
    a.display();

}