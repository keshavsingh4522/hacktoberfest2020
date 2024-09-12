// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
    public:
    
    Node *Reverse(Node *up)
    {
      Node *back=NULL;
      Node *mid=NULL;
      
      while(up!=NULL)
      {
          back=mid;
          mid=up;
          up=up->next;
          
          mid->next=back;
          
      }
     
      return mid;    
    }
    
    
    Node* addOne(Node *head) 
    {
      head=Reverse(head);
      Node *ptr=head;
      
       int result=0;
       int carry=0;
      
       if(ptr->data<9)
       {
          ptr->data+=1;
          head=Reverse(head);
          return head; 
        }
       
       else
       {
        int flag=0;  
        while(ptr)
        {
          if(flag==0)
          {
              flag=1;
              result=ptr->data+1;
              carry=result/10;
              ptr->data=result%10;
          }
          else
          {
              result=ptr->data+carry;
              carry=result/10;
              ptr->data=result%10;
          }
          
          ptr=ptr->next;
        }
       }
       
      if(carry!=0)
      {
          Node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        
        Node *t=new Node(carry);
        temp->next=t;
        
      }
      head=Reverse(head);
      return head;
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends
