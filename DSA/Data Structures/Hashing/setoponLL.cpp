#include<bits/stdc++.h> 
using namespace std;
struct Node
{
    int elem;
    Node* next;
};
Node* createNewNode(int x)
{
  Node* temp = new Node();
  temp->elem = x;
  temp->next = NULL;
  return temp;
}
class LinkedList
{
    public:
    Node *head=NULL,*tail=NULL;

    
    void insertatbeg(int x)
    {
        Node *insert = createNewNode(x);
        
        if(head==NULL)
        head = insert;

        else
        {
            insert->next = head;
            head = insert;
        }
          
    }

    void Display()
    {
        Node* temp = head;
        while(temp!=NULL)
        {
            cout<<temp->elem<<" ";
            temp = temp->next;
        }
    }
};

int main()
{
    int m,n,x;
    LinkedList a,b,c,d;
    cout<<"Enter number of elements in first LL: ";
    cin>>n;
    cout<<"\nEnter elements of first LL: ";
    for(int i = 0;i<n;i++)
    {
          cin>>x;
          a.insertatbeg(x);
    }
    cout<<"\nEnter number of elements in second LL: ";
    cin>>m;
    cout<<"\nEnter elements in second LL: ";
    for(int i = 0;i<m;i++)
    {
        cin>>x;
        b.insertatbeg(x);
    }
    map<int,int> alpha;

    Node* temp = a.head;
    
    while(temp!=NULL)
    {
        alpha[temp->elem]++;
          d.insertatbeg(temp->elem);
        temp = temp->next;
      
    }

    temp = b.head;
    while(temp!=NULL)
    {
        if(alpha.find(temp->elem)!=alpha.end())
        c.insertatbeg(temp->elem);

        else
        d.insertatbeg(temp->elem);
          
        temp = temp->next;

    }
    cout<<"\nIntersection: ";
    c.Display();
    cout<<"\n Union: ";
    d.Display();

    
}

