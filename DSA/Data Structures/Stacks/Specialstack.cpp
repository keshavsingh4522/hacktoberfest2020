#include<iostream>
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

class SpecialStack{
    Node* head=NULL,*head1=NULL;
    int size=0,minimumelem;
    
    public:
void push(int elem)
{
        Node *insert = createNewNode(elem);
     if(head == NULL)
     {head =insert;
     minimumelem = elem;}
     else
     {
        if(elem<minimumelem)
        {
            insert->elem = 2*elem-minimumelem;
            minimumelem  = elem;

        }
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
             if(head->elem<minimumelem)
             {
                 minimumelem = 2*minimumelem- head->elem;
             }

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
int getMin()
{    if(isEmpty())
    return -1;
    return minimumelem;
}

};


int main()
{
  
// Sample Test Cases were Taken for Geeks for Geeks
SpecialStack s; 
    s.push(3); 
    s.push(5); 
    cout<<"Current Minimum:"<<s.getMin();
    s.push(2); 
    s.push(1); 
    cout<<"\nCurrent Minimum:"<<s.getMin();
    s.pop(); 
    cout<<"\nCurrent Minimum:"<<s.getMin(); 
    s.pop(); 


}

