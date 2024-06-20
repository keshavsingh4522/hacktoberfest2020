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
   Stack check;
   bool balanced = true;
   cout<<"Enter Desired String\n";
   cin>>s;
    
    for( char elem:s)
    {
        if(elem=='(' || elem=='['|| elem=='{')
        check.push(elem);
        else if(elem==')' || elem==']'|| elem=='}')
        {
            char close = check.top();
            if(elem==')' && close=='(')
            check.pop();
            else if(elem==']' && close=='[')
            check.pop();
            else if(elem=='}' && close=='{')
            check.pop();
            else
            {
                balanced = false;
                break;
            }

        }
        if(!balanced)
        break;
    }
  if(!check.isEmpty())
  balanced = false;

  if(balanced)
  cout<<"String is Balanced.\n";
  else
  cout<<"String is not Balanced\n";
    return 0;
}

