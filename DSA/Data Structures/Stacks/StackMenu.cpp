#include<iostream>
#define SIZE 100
using namespace std;
struct Node{
    int elem;
    Node* next;
};
Node* createNewNode(int x)
    {
    Node *temp = new Node();
    temp->elem = x;
    temp->next = NULL;
    return temp;
    }
class Stack{
    Node* head;
    int size,capacity;
    
    public:
    
    Stack(int x)
    {  head = NULL;
        capacity = x;
        size = 0;
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
bool isFull()
{
    return size==capacity;
}
bool isEmpty()
{
    return size==0;
}

};
int main()
{
    int choice,elem;
    Stack obj(SIZE);
    while(true)
    {  cout<<"\nStack Menu:\n1.Push\n2.Pop\n3.Top\n4.Check whether Stack is Empty\n5.Check whether Stack is Full\n6.Display\n7.Exit\n"; 
        
        cin>>choice;
        switch(choice)
        {
            case 1: cout<<"Enter element to be pushed ";
            cin>>elem;
            obj.push(elem);
            break;

            case 2: 
            cout<<"Popping element..";
            obj.pop();
            break;

            case 3:
            cout<<"Top element of Stack is: "<<obj.top();
            cout<<"\n";
            break;

            case 4:
            if(obj.isEmpty())
            cout<<"Stack is Empty\n";
            else
            cout<<"Stack is not Empty\n";
            break;

            case 5:
            if(obj.isFull())
            cout<<"Stack is Full\n";
            else
            cout<<"Stack is not Full\n";
            break;

            case 6:
            cout<<"Stack Looks Like\n";
            obj.traverse();
            break;

            case 7:
            cout<<"Bye Bye..\n";
            exit(1);
            break;

            default:
            cout<<"Wrong Choice !! Try Again!!\n";
            break;


        }
    }

    return 0;
}

