#include<iostream>
#include<string>
using namespace std;
struct Node{
    char elem;
    Node* next;
};
Node* createNewNode(char x)
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
void push(char elem)
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
char top()
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
   string s;
   Stack reversedString;
   cout<<"Enter Desired String\n";
   cin>>s;
  for(char elem:s)
  {
      reversedString.push(elem);
  }
  cout<<"Reversed String is: ";
  while(!reversedString.isEmpty())
  {
      cout<<reversedString.top();
      reversedString.pop();
  }
    
    return 0;
}

