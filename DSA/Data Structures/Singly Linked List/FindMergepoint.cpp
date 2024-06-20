#include<bits/stdc++.h> 
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    int getIntersectionNode(Node *head1,Node*head2)
    {
        int size1=0,size2=0;
        bool intersectionfound = false;
        Node *ptr = head1;
       
        while(ptr!=NULL)
        {
            size1++;
            ptr = ptr->next;
        }
        ptr = head2;

         while(ptr!=NULL)
        {
            size2++;
            ptr = ptr->next;
        }

        int d  = abs(size1-size2);
        if(size1>size2)
        {
            ptr = head1;
            Node *ptr2 = head2;
         
         while(d--)
         ptr = ptr->next;

        while(ptr!=NULL && ptr2!=NULL)
        {
            if(ptr->next == ptr2->next)
               return ptr->next->data;
            
            ptr=ptr->next;
            ptr2=ptr2->next;
            
        }
         
        }
        else
        {
         
               ptr = head2;
            Node *ptr2 = head1;
         
         while(d--)
         ptr = ptr->next;

        while(ptr!=NULL && ptr2!=NULL)
        {
            if(ptr->next == ptr2->next)
               return ptr->next->data;
            
            ptr=ptr->next;
            ptr2=ptr2->next;
            
        }
                
        }
        return -1;
    }
    
};
int main() 
{ 
    /*  
        Create two linked lists  
      
        1st 3->6->9->15->30  
        2nd 10->15->30  
      
        15 is the intersection point  
    */
  
    Node* newNode,a;
  
    // Addition of new nodes 
    Node* head1 = new Node(); 
    head1->data = 10; 
  
    Node* head2 = new Node(); 
    head2->data = 3; 
  
    newNode = new Node(); 
    newNode->data = 6; 
    head2->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 9; 
    head2->next->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 15; 
    head1->next = newNode; 
    head2->next->next->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 30; 
    head1->next->next = newNode; 
  
    head1->next->next->next = NULL; 
  
    cout << "The node of intersection is " << a.getIntersectionNode(head2, head1); 
} 
  
