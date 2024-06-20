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

void traverse()
{
    Node* ptr = head;
    while(ptr!=NULL)
    {
        cout<<ptr->elem<<"<->";
        ptr = ptr->next;
    }
}
void correctNode()
{
    if(head==NULL)
    {cout<<"Linked List empty!!!\n";
    return ;}
    
    Node* temp = head;
    while(temp->next!=NULL)
    {
        if(temp->next->prev!=temp)
        temp->next->prev=temp;
        temp = temp->next;
    }
}
int main()
{  
  // Sample Test Case for Input
    head = createNode(1);
    head->next = createNode(2); 
    head->next->prev = head; 
   head->next->next = createNode(3); 
   head->next->next->prev =head; 
    head->next->next->next = createNode(4); 
    head->next->next->next->prev = head->next->next; 

    cout<<"\nCorrected Linked List is:\n";
    traverse();
return 0;
}
