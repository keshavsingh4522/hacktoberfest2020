#include<iostream>
using namespace std;
struct Node
{
    int elem;
    Node *next;
};
Node* createNode(int x)
{
    Node* temp = new Node();
    temp->elem = x;
    temp->next = NULL;
    return temp;
}
//Linked List Should not be Empty
bool isCircular(Node* head)
{
    Node *temp= head;
    while(temp!=NULL)
    {
        temp = temp->next;
        if(temp==head)
        return true;
        
    }
    return false;

}
int main()
{
// Main function Taken from Geeks for Geeks for simplicity
/* Start with the empty list */
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
 
    isCircular(head)? cout << "Yes\n" :
                      cout << "No\n" ;
 
    // Making linked list circular
    head->next->next->next->next = head;
 
    isCircular(head)? cout << "Yes\n" :
                      cout << "No\n" ;
 
    return 0;
}
