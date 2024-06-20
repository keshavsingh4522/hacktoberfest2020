#include<iostream>
#include<string>
using namespace std;
struct Node 
{
    char elem;
    Node* next;
};
Node* createNewNode(char x)
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
        
         void enqueue(char x)
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

         char peek()
         {
            if(head!=NULL)
            return head->elem;
            
            return -1;
         }


};
int main()
{
    string s;
    int alphacount[26]={0};
    cout<<"Enter String stream\n";
    cin>>s;
    Queue a(s.size()),b(s.size());
  for(char elem:s)
    { 
       a.enqueue(elem);
    }
    for(int i = 0;i<s.size();i++)
    {
        if(alphacount[a.peek()-'a']>0)
            b.enqueue('0');
        else
        {
            b.enqueue(a.peek());
            alphacount[a.peek()-'a']++;
        }
       a.dequeue();
    
    }
    b.display();


}