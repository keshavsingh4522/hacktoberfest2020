#include <iostream>
#include <cstddef>
using namespace std;
/**
 * 
 *  Aman Upadhyay
 *  Amity University Kolkata
 * 
*/
class Node
{
    public:
          int data;
          Node *next;
          Node(int d)
          {
              data = d;
              next = NULL;
          }
};

class Solution
{
    public:
        Node* insert(Node *head, int data)
          {
              Node* newnode = new Node  (data);
                         if (head == NULL)
                         {
                             return newnode;
                         }
              Node* it = head;
              while (it -> next != NULL)
              {
                  it = it -> next;
              }
              it -> next = newnode;
              return head;           
          }

         void display(Node *head)
         {
             Node *start = head;
             while (start)
             {
                 cout << start -> data << " ";
                 start = start -> next;
             }
         }
};

int main()
{
    Node* head = NULL;
         Solution mylist;
         int T, data;
         cin >> T;

         while (T --> 0)
         {
             cin >> data;
             head = mylist.insert(head, data);
         }
         mylist.display(head);
}