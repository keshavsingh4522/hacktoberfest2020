#include <iostream>
using namespace std;
 
// A linked list node
struct Node
{
   int data;
   struct Node *next;
};

void push(struct Node** head, int node_data)
{
   
   struct Node* newNode = new Node;
 
  
   newNode->data = node_data;
 
   
   newNode->next = (*head);
 
   
   (*head) = newNode;
}
 

void insertAfter(struct Node* prev_node, int node_data)
{

if (prev_node == NULL)
{
   cout<<"the given previous node is required,cannot be NULL"; return; } 
 
   
   struct Node* newNode =new Node; 
 

   newNode->data = node_data;
 
   
   newNode->next = prev_node->next;
 
    
    prev_node->next = newNode;
}
 

void append(struct Node** head, int node_data)
{

struct Node* newNode = new Node;
 
struct Node *last = *head; 
 

newNode->data = node_data;
 

newNode->next = NULL;
 

if (*head == NULL)
{
*head = newNode;
return;
}
 

while (last->next != NULL)
last = last->next;
 

last->next = newNode;
return;
}
 

void displayList(struct Node *node)
{
   
   while (node != NULL)
   {
      cout<<node->data<<"-->";
      node = node->next;
   }
 
if(node== NULL)
cout<<"null"; 
} 

int main() 
{ 

struct Node* head = NULL; 
 

append(&head, 10); 
 

push(&head, 20); 
 
 
push(&head, 30); 
 

append(&head, 40); 
 

insertAfter(head->next, 50);
 
cout<<"Final linked list: "<<endl;
displayList(head);
 
return 0;

}
