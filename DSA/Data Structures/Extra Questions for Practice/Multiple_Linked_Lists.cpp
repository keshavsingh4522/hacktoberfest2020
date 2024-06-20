#include<bits/stdc++.h>
using namespace std;
bool circular = false;
struct Node{
    int elem;
    Node* next;
}*head=NULL,*tail=NULL;
map<Node*,int> nodes;
Node* createnewNode(int x)
{
    Node* temp = new Node();
    temp->elem = x;
    temp->next = NULL;
    return temp;
}
void insertinbeg(Node* insert)
{
    if(head==NULL)
    head = tail = insert;
    else
    {
        tail->next = insert;
        nodes[insert]++;
        tail = insert;
    }
}
void insertatplace(int x,int y)
{
    Node* temp = head,*prev= NULL;
    while(temp!=NULL)
    {
        if(temp->elem==y)
        {
            Node* insert = createnewNode(x);
            insert->next = temp->next;
            temp->next = insert;
            if(temp ==tail)
            tail = insert;
            nodes[insert]++;
            return ;
        }
        temp = temp->next;
    }
  
     Node* insert= createnewNode(y);
       if(head->elem==x)
       {
           insert->next = head;
          nodes[head]++;
           head = insert;
       }
       else
       {  temp = head;
          while(temp!=NULL)
          {
              if(temp->elem==x)
              {
                  insert->next = prev->next;
                  prev->next = insert;
                 nodes[insert]++;
                  return ;
              }
              prev = temp;
              temp = temp->next;
          }
       }
       
    
}
void insertinbetween(int low,int high,Node* insert)
{
    Node *start=NULL, *end=NULL,*temp=head;
    while(temp->elem!=low)
    {
       temp= temp->next;
    }
  
   start = temp;
   Node *fast=start,*superfast=start,*prev=NULL;
   
    while(superfast->elem!=high && superfast->next->elem!=high  )
    {  prev = fast;
       superfast = superfast->next->next;
       fast = fast->next;
        
    }
    if(superfast->elem==high)
    {
         insert->next = prev->next ;
         prev->next = insert;
         nodes[insert]++;
    }
    else{
    insert->next = fast->next;
    fast->next = insert;
   nodes[insert]++;
    }
    
}
void traverse()
{
    Node* temp = head;
    do 
    {
        cout<<temp->elem<<" ";
        temp = temp->next; 
    }while(temp!=NULL && temp!=head);
}
void changeaddrp(int x,int position)
{  
    Node*temp = head,*curr;
    bool elem_found = false;
    int curr_index =0;
    while(true)
    {
         
         if(temp->elem== x && !elem_found)
         {curr = temp;
         elem_found = true;
         curr_index = 0;
        }
         if(curr_index==position && elem_found)
         {  
             nodes[curr->next]--;
              curr->next = temp;
             nodes[temp]++;
              break;
         }
         if(temp->next == NULL)
         {  
             temp->next = head;
            nodes[head]++;
             circular = true;

         }
         curr_index++;
         temp = temp->next;
         
    }

}

int main()
{
int t,choice,x,y,z,p;
char ex;
cin>>t;
while(t--)
{
   cin>>ex;
    if(ex=='I')
    {
 cin>>choice;
 switch(choice)
 {
     case 0:

     cin>>x;
     insertinbeg(createnewNode(x));
     break;

    case 1:
    cin>>y>>x;
    insertatplace(x,y);
    break;

    case 2:
   cin>>z>>y>>x;
  insertinbetween(z,y,createnewNode(x));
   break;
 }
    }
    else 
    {
        cin>>x>>p;
        changeaddrp(x,p);
    }
    
}
cout<<circular<<"\n";
vector<int> elem;
map<int,int> hh;
for(auto it = nodes.begin();it!=nodes.end();it++)
{
    if(it->second>=2)
    {elem.push_back(it->first->elem);
    hh.insert(make_pair(it->first->elem,it->second));}
}
cout<<elem.size()<<"\n";
if(elem.size()==0)
traverse();
else
{ 
    for(int ch:elem)
    cout<<ch<<" ";
}
cout<<"\n";
if(elem.size()!=0)
{
    for(int ch:elem)
    cout<<hh[ch]<<" ";
}


return 0;
}