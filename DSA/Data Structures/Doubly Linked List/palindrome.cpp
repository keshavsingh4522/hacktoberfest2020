#include<iostream>
using namespace std;
struct Node
{
    char elem;
    Node *next,*prev;
}*head=NULL,*tail=NULL;
Node* createNode(char x)
{
    Node* temp = new Node();
    temp->elem = x;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void insertfrombeg(Node* insert)
{
    if(head==NULL)
    head = tail = insert;
    else
    {
        insert->next = head;
        head->prev = insert;
        head = insert;

    }
}
bool checkpalindrome()
{
    Node* begin = head,*end= tail;
    while(begin!=NULL && end!=NULL)
    {
     if(begin->elem != end->elem)
     return false;

     begin = begin->next,end = end->prev;
    }
    return true;
}
int main()
{
// Taking a Palindromic String
string s = "naman";
// Inserting characters of Palindrome to a Doubly Linked List
for(char x:s)
insertfrombeg(createNode(x));

if(checkpalindrome())
cout<<"Palindromic\n";
else
cout<<"Not Palindromic\n";

return 0;
}
