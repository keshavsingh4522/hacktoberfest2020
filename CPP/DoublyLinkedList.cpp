#include <iostream>
using namespace std;
  
// A doubly linked list node
struct Node {
   int data;
   struct Node* next;
   struct Node* prev;
};
  
//inserts node at the front of the list
void insert_front(struct Node** head, int new_data)
{
   //allocate memory for New node
   struct Node* newNode = new Node;
  
   //assign data to new node
   newNode->data = new_data;
  
   //new node is head and previous is null, since we are adding at the front
   newNode->next = (*head);
   newNode->prev = NULL;
  
   //previous of head is new node
   if ((*head) != NULL)
   (*head)->prev = newNode;
  
   //head points to new node
   (*head) = newNode;
}
/* Given a node as prev_node, insert a new node after the given node */
void insert_After(struct Node* prev_node, int new_data)
{
   //check if prev node is null
   if (prev_node == NULL) {
   cout<<"Previous node is required , it cannot be NULL";
   return;
}
   //allocate memory for new node
   struct Node* newNode = new Node;
  
   //assign data to new node
   newNode->data = new_data;
  
   //set next of newnode to next of prev node
   newNode->next = prev_node->next;
  
   //set next of prev node to newnode
   prev_node->next = newNode;
  
   //now set prev of newnode to prev node
   newNode->prev = prev_node;
  
   //set prev of new node's next to newnode
   if (newNode->next != NULL)
   newNode->next->prev = newNode;
}
  
//insert a new node at the end of the list
void insert_end(struct Node** head, int new_data)
{
   //allocate memory for node
   struct Node* newNode = new Node;
  
   //set last node value to head
   struct Node* last = *head; 
  
   //set data for new node
   newNode->data = new_data;
  
   //new node is the last node , so set next of new node to null
   newNode->next = NULL;
  
   //check if list is empty, if yes make new node the head of list
   if (*head == NULL) {
   newNode->prev = NULL;
   *head = newNode;
    return;
}
  
//otherwise traverse the list to go to last node
while (last->next != NULL)
last = last->next;
  
//set next of last to new node
last->next = newNode;
  
//set last to prev of new node
newNode->prev = last;
return;
}
  
// This function prints contents of linked list starting from the given node
void displayList(struct Node* node) {
   struct Node* last;
  
   while (node != NULL) {
      cout<<node->data<<"<==>";
      last = node;
      node = node->next;
   }
   if(node == NULL)
   cout<<"NULL";
   }
  
//main program
int main() {
   /* Start with the empty list */
   struct Node* head = NULL;
  
   // Insert 40 as last node
   insert_end(&head, 40);
  
   // insert 20 at the head
   insert_front(&head, 20);
  
   // Insert 10 at the beginning.
   insert_front(&head, 10);
  
   // Insert 50 at the end.
   insert_end(&head, 50);
  
   // Insert 30, after 20.
   insert_After(head->next, 30);
  
   cout<<"Doubly linked list is as follows: "<<endl;
   displayList(head);
   return 0;
}
Output:

Doubly linked list is as follows:

10<==>20<==>30<==>40<==>50<==>NULL

The above program constructs a doubly linked list by inserting the nodes using three insertion methods i.e. inserting the node at the front, inserting the node at the end and inserting the node after the given node.

Next, we demonstrate the same operation as a Java implementation.

// Java Class for Doubly Linked List
class Doubly_linkedList {
   Node head; // list head
  
    /* Doubly Linked list Node*/
   class Node {
      int data;
      Node prev;
      Node next;
  
      //create a new node using constructor
      Node(int d) { data = d; }
   }
  
// insert a node at the front of the list
public void insert_front(int new_data)
{
   /* 1. allocate node
   * 2. put in the data */
   Node new_Node = new Node(new_data);
  
   /* 3. Make next of new node as head and previous as NULL */
   new_Node.next = head;
   new_Node.prev = null;
  
   /* 4. change prev of head node to new node */
   if (head != null)
   head.prev = new_Node;
  
   /* 5. move the head to point to the new node */
   head = new_Node;
}
//insert a node after the given prev node
public void Insert_After(Node prev_Node, int new_data)
{
   //check that prev node is not null
   if (prev_Node == null) {
   System.out.println("The previous node is required,it cannot be NULL ");
   return;
}
  
   //allocate new node and set it to data
   Node newNode = new Node(new_data);
  
   //set next of newNode as next of prev node
   newNode.next = prev_Node.next;
  
   //set new node to next of prev node
   prev_Node.next = newNode;
  
   //set prev of newNode as prev node
   newNode.prev = prev_Node;
  
   //set prev of new node's next to newnode
   if (newNode.next != null)
   newNode.next.prev = newNode;
}
  
// Add a node at the end of the list
void insert_end(int new_data)   {
   //allocate the node and set the data
   Node newNode = new Node(new_data);
   Node last = head; //set last as the head
   //set next of new node to null since its the last node
   newNode.next = null;
  
   //set new node as head if the list is null
   if (head == null) {
      newNode.prev = null;
      head = newNode;
      return;
   }
   //if list is not null then traverse it till the last node and set last next to last
   while (last.next != null)
   last = last.next;
  
   last.next = newNode;           //set last next to new node
  
   newNode.prev = last;           //set last as prev of new node
}
// display the contents of linked list starting from the given node
public void displaylist(Node node)
{
   Node last = null;
   while (node != null) {
      System.out.print(node.data + "<==>");
      last = node;
      node = node.next;
   }
   if(node == null)
   System.out.print("null");
   System.out.println();
  
   }
}
class Main{
   public static void main(String[] args)
      {
      /* Start with the empty list */
      Doubly_linkedList dll = new Doubly_linkedList();
  
      // Insert 40.
      dll.insert_end(40);
  
      // Insert 20 at the beginning.
      dll.insert_front(20);
  
      // Insert 10 at the beginning.
      dll.insert_front(10);
  
      // Insert 50 at the end.
      dll.insert_end(50);
  
      // Insert 30, after 20.
      dll.Insert_After(dll.head.next, 30);
  
      System.out.println("Doubly linked list created is as follows: ");
      dll.displaylist(dll.head);
      }
}
