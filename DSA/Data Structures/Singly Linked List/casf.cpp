#include<iostream>
using namespace std;
struct node{
 int data;
 node *next;
};
class linked_list
{
private:
    node *head,*tail;
public:
    linked_list()
    {
        head=NULL;
        tail=NULL;
    }
    void push(int data)
    {
        node *new_node= new node;
        new_node->data=data;
        new_node->next=NULL;
        if(head==NULL)
        {
           head=new_node;
           tail=new_node;
        }
        else
        {
            tail->next=new_node;
            tail= tail->next;
        }
    }
  void reverse(int m,int n)
  {
    if(head==NULL)
    {
       cout<<"Empty"<<endl;
    }
    else{
       node *prev=NULL;
    node *ptr=head;
    while(m>1)
    {
       prev=ptr;
       ptr=ptr->next;
       m--;
       n--;
    }
    node *conn=prev;
    node *tail=ptr;
    while(n>0)
    {
      node *next_node=ptr->next;
      ptr->next=prev;
      prev=ptr;
      ptr=next_node;
      n--;
    }
    if(conn!=NULL)
    {
      conn->next=prev;
    }
    else
       head=prev;

       tail->next=ptr;

    }

  }

    void print()
    {
        node *ptr;
        ptr=head;
        while(ptr!=NULL)
        {
            //cout<<head->data<<" ";
            cout<<ptr->data<<" ";
            ptr= ptr->next;
        }
    }

};
int main()
{
    linked_list a;
    int k;
   cout<<"Enter elements in a linked list:"<<endl;
   cin>>k;
   cout<<"Enter elements:"<<endl;
   for(int i=0;i<k;i++)
     {
       int e;
       cin>>e;
       a.push(e);
     }
     int m,n;
     cout<<"Enter m and n for reversing list:"<<endl;
     cin>>m>>n;
     a.reverse(m,n);
     cout<<endl;
     a.print();
}
