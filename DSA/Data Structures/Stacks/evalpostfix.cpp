
/* This Code works for Single Digit Operand Only */
#include<iostream>
#include<string>
#include<cmath>
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
int evalexpr(string s)
{
    Stack obj;
    int val1,val2;
    for(char elem: s)
    {
        if(elem>='0' && elem<='9')
        obj.push(elem-'0');
        else 
        {    val1 = obj.top();
        obj.pop();
        val2 = obj.top();
        obj.pop();
              switch(elem)
              {
                  case '-' : obj.push(val2-val1);  break;
                  case '+': obj.push(val2+val1);  break;
                  case '*': obj.push(val2*val1);  break;
                  case '/':obj.push(val2/val1);  break;
                  case '^':obj.push(pow(val2,val1)); break;
              }
        }
    }
   return obj.top();
}

int main()
{
   string s;
   cout<<"Enter Postfix Expression to be Evaluated (Without spaces): ";
   cin>>s;
   cout<<"Result of Given Expression is: "<<evalexpr(s);

   return 0;
}

