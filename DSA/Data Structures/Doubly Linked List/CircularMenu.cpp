#include<iostream>
using namespace std;
struct Node
{
    int elem;
    Node *next;
}*head=NULL,*tail=NULL;
Node* createNode(int x)
{
    Node *ptr = new Node();
    ptr->elem = x;
    ptr->next = NULL;
    return ptr;
}
void insertattail(Node *insert)
{
   if(head==NULL)
   {
       head = tail = insert;
       head->next = head;
   }
   else
   {
        insert->next = tail->next;
        tail->next = insert;
        tail = insert;
   }
}
void insertbeforenode(Node* insert,int y)
{
   Node *ptr=head;
   if(ptr==NULL)
   {
       cout<<"Linked List Empty!!!\n";
       return ;
   }
   else if (ptr->elem== y && ptr->next == ptr)
   {
       insertattail(insert);
       return ;
   }
   do 
    {
       if(ptr->next->elem==y)
       {
          insert->next = ptr->next;
          ptr->next = insert;
          return ;

       }
       ptr = ptr->next;

    }while(ptr!=head);
    cout<<"Node not found\n";

}
void insertafternode(Node* insert,int y)
{
    Node *ptr = head;
    if(ptr==NULL)
    {cout<<"Linked List Empty!..\n";
    return ;}
    else
    {
         do
         {
             if(ptr->elem == y)
             {
                  if(ptr==tail)
                  insertattail(insert);
                else
                  {
                    insert->next = ptr->next;
                    ptr->next = insert;
                  }
                  return ;
                  
             }
             ptr = ptr->next;

         }while(ptr!=head);
    }
    cout<<"Node Not Found\n";

}
void deletenode(int x)
{
    if(head==NULL)
    cout<<"Underflow...\n";
    else if (head->elem == x)
    {   
        if(head->next == head)
        {
            delete head;
            head = NULL;
        }
        else{
        tail->next = head->next;
        Node *temp = head;
        head = head->next;
        delete temp;
        }
    }
    else
    {
        Node *ptr = head,*prev=NULL;
        do
        {    
            if(ptr->elem==x)
            {
                prev->next = ptr->next;
                delete ptr;
                return ;
            }
            prev = ptr;
            ptr = ptr->next;
        } while (ptr!=head);
        cout<<"Element not found..\n";

    }
}
void traverse()
{
    Node *ptr = head;
    if(ptr==NULL)
    return ;
    do 
    {
       cout<<ptr->elem<<" ";
       ptr = ptr->next;

    }while(ptr!=head);
}
int main()
{
    int choice,x,y;
    while(true)
    {
        cout<<"\nCircular Linked List Menu\n1.Insert at Tail\n2.Traverse\n3.Delete a node\n4.Insert After a Node\n5.Insert before a node\n6.Exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter Element\n";
            cin>>x;
            insertattail(createNode(x));
            break;

            case 2:
            cout<<"Linked List Looks Like\n";
            traverse();
            break;

            case 3:
            cout<<"Enter the node to be deleted\n";
            cin>>x;
            deletenode(x);
            break;


            case 4:
            cout<<"Enter The node to be inserted and node after\n";
            cin>>x>>y;
            insertafternode(createNode(x),y);
            break;

            case 5 :
            cout<<"Enter the node to be inserted and node before\n";
            cin>>x>>y;
            insertbeforenode(createNode(x),y);
            break;

            case 6:
            cout<<"Exiting...\n";
            exit(1);
            break;

            
            default:
            cout<<"Wrong Choice Entered\n";
            break;
            

        }
    }

return 0;
}
