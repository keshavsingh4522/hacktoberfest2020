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
bool checkparity(int n)
{
    int count_one = 0;
    while(n!=0)
    {
        if(n%2)
        count_one++;
        n/=2;
    }
    return count_one%2==0;
}
void removeevenparity()
{
    if(head==NULL)
    return;
 bool check = false;
    Node *temp = head,*prev=NULL;
    do{
        if(checkparity(temp->elem))
        {
            Node *del = temp;
            if(temp==head)
            {
                head = temp->next;
                tail->next = head;
                check = true;
            }
            else
           prev->next = temp->next; 
           temp = temp->next;
           delete(del);
        }
        else{
        prev = temp;
        temp = temp->next;
        check = false;
        }
    }while(temp!=head || check);
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
    int n,elem;
    cout<<"Enter Number of Elements in Linked List:\n";
    cin>>n;
    for(int i =0;i<n;i++)
    {
        cin>>elem;
        insertattail(createNode(elem));
    }
    removeevenparity();
    cout<<"\nLinked List Becomes:\n";
    traverse();

return 0;
}
