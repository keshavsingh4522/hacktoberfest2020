#include<iostream>
using namespace std;
struct Node
{
    int elem;
    Node* next;
}*head = NULL,*tail = NULL;
Node* createNode(int x)
{
    Node *ptr = new Node();
    ptr->elem = x;
    ptr->next = NULL;
    return ptr;
}
void insertinbeg(Node* insert)
{
    if (head == NULL)
    head = tail = insert;
    else
    {
        insert->next = head;
        head = insert;
    }
}
void insertfromend(Node *insert)
{
    if(tail == NULL)
    head = tail = insert;
    else
    {
        tail->next = insert;
        tail = insert;
    }
}
void deletefrombeg()
{
    if (head == NULL)
    cout<<"Underflow\n";
    else
    {
        Node *ptr = head;
        head = head->next;
        delete ptr;
    }
}
void deletefromend()
{
    if(head == NULL)
    cout<<"Underflow\n";
    else
    {
        Node* prev = NULL,*ptr = head;
        while(ptr->next!=NULL)
        {   prev = ptr;
            ptr = ptr->next;
        }
        prev->next = ptr->next;
        delete ptr;
    }
}
void traverse()
{
    Node *ptr = head;
    while(ptr!=NULL)
    {
        cout<<ptr->elem<<"->";
        ptr=ptr->next;

    }
    cout<<"\n";
}
void deletethisnode(int del)
{
    if(head == NULL)
    cout<<"Underflow\n";
    else if (head->elem == del)
    {
        Node *ptr = head;
        head = head->next;
        delete ptr;
    }
    else
    {  bool found = false;
        Node* prev = NULL,*ptr = head;
        while(ptr->next!=NULL )
        {   prev = ptr;
            ptr = ptr->next;
            if(ptr->elem == del)
            {
                found = true;
                break;
            }
        }
        if(found)
        {
        prev->next = ptr->next;
        delete ptr;
        }
        else
        cout<<"Element Not found";
    }

}
void insertbefore(int ins,int elem)
{
    if(head == NULL)
    cout<<"Check Again!! Linked List is Empty\n";
    else if(head->elem == ins)
    {
        Node *ptr = createNode(elem);
        ptr->next = head;
        head = ptr;
    }
    else
   {
        Node *prev= NULL,*ptr = head;
    bool found = false;
    while(ptr->next!= NULL)
    {
        prev = ptr;
        ptr = ptr->next;
        if(ptr->elem == ins)
        {
            found = true;
            break;
        }
    }
    if(found)
    {
        Node *insert = createNode(elem);
        prev->next = insert;
        insert->next = ptr;
    }
    else
    {
        cout<<"The Elemented where to insert before not found\n";
    }
 }
} 
void insertafter(int ins,int elem)
{
    if(head == NULL)
    cout<<"Check Again !!! Linked List is Empty\n";
    else
    {
        bool found = false;
        Node *ptr = head;
        while(ptr!=NULL)
        {
             if(ptr->elem == ins)    
            {
                found = true;
                break;
            }
            ptr = ptr->next;
         }
        if(found)
        {
           Node *insert = createNode(elem);
           insert->next = ptr->next;
           ptr->next = insert;
        }
        else
        {
            cout<<"Elem not Found\n";
        }
    }
}
    
    
int displaypos(int x)
{
    Node *ptr = head;
    int pos = 1;
    while(ptr!=NULL)
    {
        if(ptr->elem == x)
        break;
        pos ++;
        ptr = ptr->next;
    }
    if(ptr == NULL)
    return -1;
    else
    return pos;
}
int main()
{
int choice,x,y;


while(true)
{
cout<<"Linked List Menu\n1.Insertion From Beg\n2.Deletion From Beg\n3.Insertion From end\n4.Deletion from end\n5.Traverse\n6.Find Pos of element\n7.Delete a Particular Node\n8.Insert Before a Given Node\n9.Insert After a given Node\n10.Exit\n";
cout<<"Enter your Choice\n";
cin>>choice;
switch (choice)
{
case 1:
cout<<"Enter the element to be Inserted\n";
cin>>x;
insertinbeg(createNode(x));
break;

case 2:
cout<<"Deleting from beg\n";
deletefrombeg();
break;

case 3 :
cout<<"Enter the element to be inserted\n";
cin>>x;
insertfromend(createNode(x));
break;

case 4:
cout<<"Deleting from end\n";
deletefromend();
break;

case 5 :
cout<<"The Linked List Looks like..\n";
traverse();
break;

case 6 :
cout<<"Enter Element to be searched\n";
cin>>x;
 
if(displaypos(x)== -1)
cout<<"Element Not found\n";
else
cout<<"Pos of The Element is "<<displaypos(x)<<"\n";
break;

case 7 :
cout<<"Enter Element to be Deleted\n";
cin>>x;
deletethisnode(x);
break;

case 8 :
cout<<"Enter the element before which you want to Insert and the element Itself\n";
cin>>x>>y;
insertbefore(x,y);
break;

case 9 :
cout<<"Enter the element after which you want to Insert and the element Itself\n";
cin>>x>>y;
insertafter(x,y);
break;

case 10 :
cout<<"Exiting...";
exit(1);
break;

default:
cout<<"Wrong Choice Entered\n";
    break;
}
}
return 0;
}
