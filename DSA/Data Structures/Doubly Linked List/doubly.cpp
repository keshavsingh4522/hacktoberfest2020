#include<iostream>
using namespace std;
struct Node
{
    int elem;
    Node *next,*prev;
}*head=NULL,*tail=NULL;
Node* createNode(int x)
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
void insertfromend(Node *insert)
{
   if(tail==NULL)
   head = tail = insert;
   else
   {
       tail->next = insert;
       insert->prev = tail;
       tail = insert;
   }
}
void deletenode(int x)
{
    bool found = false;
     if(head==NULL)
     {cout<<"Underflow!!!\n";
     return ;}
    Node* ptr = head;
    while(ptr!=NULL)
    {
        if(ptr->elem == x)
        {   found = true;
             Node* temp = ptr;
            
            if(ptr == head)
               head = head->next;
            
            else if (ptr==tail)
           {tail = ptr->prev;
           tail->next = NULL;}
          
            else
         {
             ptr->next->prev = ptr->prev;
             ptr->prev->next = ptr->next;
         }
            
            delete temp;
            break;
        }
        ptr = ptr->next;
    }
    if(!found)
    cout<<"Element not found\n";

}
void traverse()
{
    Node* ptr = head;
    while(ptr!=NULL)
    {
        cout<<ptr->elem<<"<->";
        ptr = ptr->next;
    }
}
void search(int x)
{
    Node* ptr = head;
    int count = 0;
    while(ptr!=NULL)
    {
        if(ptr->elem==x)
        {
            cout<<"Node found at pos: "<<count<<"\n";
            return ;
        }
        ptr = ptr->next,count++;
    }
    cout<<"Node not found\n";
}
void insertbefore(Node* insert,int x)
{
    Node* ptr = head;
    while(ptr!=NULL)
    {
        if(ptr->elem == x)
        {
            if(ptr==head)
            insertfrombeg(insert);
             else{
              ptr->prev->next = insert;
              insert->prev = ptr->prev;
              insert->next = ptr;
              ptr->prev = insert;
             }
              return ;
        }
        ptr = ptr->next;
    }
    cout<<"Specified element not found\n";
}
void insertafter(Node *insert,int x)
{
    Node* ptr = head;
    while(ptr!=NULL)
    {
        if(ptr->elem == x)
        {   
            if(ptr == tail)
            insertfromend(insert);
            
            else{
            ptr->next->prev = insert;
            insert->next = ptr->next;
            insert->prev = ptr;
            ptr->next = insert;
            }
            return;
        }
        ptr = ptr->next;
    }
    cout<<"Element Not found!!!\n";
}
int main()
{  int choice,x,y;
   while(true)
   {
       
         cout<<"\nDoubly Linked List Menu:\n1.Insert from Beg\n2.Insert from end\n3.Traverse\n4.Delete a particular node\n5.Insert Before a Node\n6.Insert after a Node\n7.Exit\n";
           cin>>choice;
         switch (choice)
         {
         case 1:
        cout<<"Enter element\n";
        cin>>x;
        insertfrombeg(createNode(x));
             break;

        case 2:
        cout<<"Enter element\n";
        cin>>x;
        insertfromend(createNode(x));
         break;

         case 3:
         cout<<"Doubly linked List Looks like\n";
        traverse();
        break;
       
        case 4 :
        cout<<"Enter element to be deleted\n";
        cin>>x;
        deletenode(x);
        break;

        case 5 :
        cout<<"Enter element and Node before to be inserted\n";
        cin>>x>>y;
        insertbefore(createNode(x),y);
        break;


        case 6 :
        cout<<"Enter element and node after to be inserted\n";
        cin>>x>>y;
        insertafter(createNode(x),y);
        break;

        case 7:
        exit(1);
        break;

         default:
         cout<<"Wrong Choice Entered\n";
         break;
            
         }
   }

return 0;
}
