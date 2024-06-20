#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int  elem;
    Node* next;
};
Node* createNewNode(int  x)
    {
    Node *temp = new Node();
    temp->elem = x;
    temp->next = NULL;
    return temp;
    }

class Stack{
    Node* head=NULL;
    int size=0;
    
    public:
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
     size++;
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
                size--;
        }
      
}
int top()
{
    if(head!=NULL)
    return head->elem;

    return -1;
}
bool isEmpty()
{
    return size==0;
}

};


int main()
{
   int n;
   Stack obj;
   cout<<"Enter Number of elements in Array: ";
   cin>>n;
   vector<int> x(n);
   cout<<"\n Enter elements in Array: ";
   for(int i =0;i<n;i++)
   cin>>x[i];

    for(int i =0;i<x.size();i++)
    {
        
    while(!obj.isEmpty() && obj.top()>=x[i])
    obj.pop();
            
        if(obj.isEmpty())
        cout<<"-1 ";
        else
        cout<<obj.top()<<" ";

        
        obj.push(x[i]);
    }

}

