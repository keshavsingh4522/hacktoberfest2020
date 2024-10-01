#include<iostream>

using namespace std;
class Node
{
    public:
    int data;
    Node*next;
};
class List:public Node
{
    Node *listptr ,*temp,*q;
    public:
    List()
    {
        listptr=NULL;
        temp=NULL;
    }
    void create();
    void display();
    void insertion_end();
    void insertionbeg();
    void insertion_mid();
    void deletion_end();
    void deletionbeg();
    void deletion_mid();
    void reverse();
    void concat(List o,List j);
};
void List::create()
{
    int g,i,x;
    cout<<"enter no of nodes";
    cin>>g;
    for(i=0;i<g;i++)
    {
        Node*newnode=new Node;
        cout<<"enter data";
        cin>>x;
        newnode->data=x;
        newnode->next=NULL;
        if(listptr==NULL)
        {
            listptr=newnode;
            temp=newnode;
            newnode->next=listptr;
        }
        else
        {
            temp->next=newnode;
            newnode->next=listptr;
            temp=temp->next;

        }
    }

}
void List::display()
{

	Node *temp = listptr;
    cout<<"Data is -:";
    cout<<temp->data<<" ";
    cout<<endl;
	while(temp->next != listptr)
    {
		temp = temp->next;
		cout<<"Data is -:"<<temp->data<<" " ; 
        cout<<endl;
	}
	
	
}
void List::insertionbeg()
{
    int x;
    Node*newnode=new Node;
    cout<<"enter data";
    cin>>x;
    newnode->data=x;
    newnode->next=NULL;
    temp=listptr; 
    while (temp->next!=listptr)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=listptr;
    listptr=newnode;
    
}
void List::insertion_end()
{
    int x;
    Node*newnode=new Node;
    cout<<"enter data";
    cin>>x;
    newnode->data=x;
    newnode->next=NULL;
    temp=listptr;
    while(temp->next!=listptr)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=listptr;

}
void List::insertion_mid()
{
    int x,y;
    int i=0;
    temp=listptr;
    Node*newnode=new Node;
    cout<<"enter data";
    cin>>x;
    newnode->data=x;
    newnode->next=NULL;
    cout<<"enter node after which you want to insert";
    cin>>y;
    while(i!=y-1)
    {
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;

}
void List::deletionbeg()
{
    temp=listptr=q;
    while (temp->next!=listptr)
    {
        temp=temp->next;

    }
    listptr=listptr->next;
    temp->next=listptr;
    delete(q);
}
void List::deletion_end()
{
    temp=listptr;
    //Node*q;
    while(temp->next->next=listptr)
    {
        temp=temp->next;
    }
    q=temp->next;
    temp->next=listptr;
    delete(q);
}
void List::deletion_mid()
{
    int y,i;
    temp=listptr;
    Node*q;
    cout<<"enter node after which you want to delete";
    cin>>y;
    for(i=0;i<y-1;i++)
    {
        temp=temp->next;
    }
    q=temp->next;
    temp->next=q->next;
    delete(q);
}
void List::concat(List o,List j)
{
    Node* temp2;
    temp=o.listptr;
    while (temp->next!=listptr)
    {
        temp=temp->next;

    }
    temp->next=j.listptr;
    temp2=j.listptr;
    while (temp2->next!=j.listptr)
    {
        temp2=temp2->next;

    }
    temp2->next=listptr;

}
void List::reverse()
{
    Node *forw,*curr,*back;
    back=NULL;
    curr=listptr;
    forw=NULL;
    
   do
   {
       forw=curr->next;
       curr->next=back;
       back=curr;
       curr=forw;
   } while (curr!=listptr);

        listptr->next=back;
        listptr=back;
   

}
int main()
{
    int p=1,ch;
    List l;
    List u;
    while (p==1)
    {
        cout<<"\n Enter choice \n 1-create\n 2-display\n 3-Insertion At Beginning\n 4-Insertion At end\n 5-insertion At mid";
        cout<<"6-Deletion At Beginning\n 7-Deletion At end\n 8-Deletion At mid \n 9-Reverse \n 10- Concat ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                l.create();
                break;
            case 2:
                l.display();
                break;
            case 3:
                l.insertionbeg();
                break;
            case 4:
                l.insertion_end();
                break;
            case 5:
                l.insertion_mid();
                break;
            case 6:
                l.deletionbeg();
                break;
            case 7:
                l.deletion_end();
                break;
            case 8:
                l.deletion_mid();
                break;
            case 9:
                l.reverse();
                break;
            case 10:
                u.create();
                l.concat(l,u);

                break;
        }
    
    cout<<"\n Press 1 to continue \n";
    cin>>p;
}
return 0;
}
