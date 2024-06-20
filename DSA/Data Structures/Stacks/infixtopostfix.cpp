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
int precedence(char op)
{
    if(op=='^')
    return 3;
    else if (op=='/' || op=='*')
    return 2;
    else if(op=='+'|| op=='-')
    return 1;
    
    return -1;
}
string convertinfixtopostfix(string s)
{
    Stack obj;
    string ans;
    for(char elem:s)
    {
        if(elem=='(')
        obj.push(elem);
        else if(elem==')')
        {
            while( !obj.isEmpty() && obj.top()!='(' )
            {   
            ans+=obj.top();
            obj.pop();}
            obj.pop(); 
        }
        else if(elem>='a' && elem<='z')
    ans+=elem;
        else
        {
             while(!obj.isEmpty() && precedence(elem)<=precedence(obj.top()))
             {
              ans+=obj.top();
                 obj.pop();
             }
             obj.push(elem);
        }

    }
    while(!obj.isEmpty())
    {
        ans+=obj.top();
        obj.pop();

    }
    return ans;
}
int main()
{
    string s;
    cout<<"Enter Infix Expression: ";
    cin>>s;
    cout<<"\n"<<convertinfixtopostfix(s);

   return 0;
}

