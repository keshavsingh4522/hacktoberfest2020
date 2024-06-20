#include<iostream>
#include<string>
using namespace std;
struct Node 
{
    string elem;
    Node* next;
};
Node* createNewNode(string x)
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
        
         void enqueue(string x)
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
         string peek()
         {
            if(head!=NULL)
            return head->elem;
            
            return "-1";
         }


};
int main()
{
    int n;
    string s1,s2;
    cout<<"Enter n for generating binary numbers from 1 to n: ";
    cin>>n;
    Queue a(n+1);
    a.enqueue("1");
    cout<<"\nRequired series is: \n";
    while(n--)
    {
          s1 = a.peek();
          cout<<s1<<"\n";
          a.dequeue();
          s2 = s1;
          a.enqueue(s1.append("0"));
          a.enqueue(s2.append("1"));
    }
}
