#include<iostream>

using namespace std;
class Node
{
    public:
    int data;
    Node*next;
    Node*prev;
};
class List:public Node
{
    Node *listptr ,*temp;
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
        newnode->prev=NULL;
        if(listptr==NULL)
        {
            listptr=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
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
	while(temp->next != NULL)
    {
		temp = temp->next;
		cout<<"Data is -:"<<temp->data<<" " ; 
        cout<<endl;
	}
	cout<<endl;
	
}
void List::insertionbeg()
{
    int x;
    Node*newnode=new Node;
    cout<<"enter data";
    cin>>x;
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;
    newnode->next=listptr;
    listptr->prev=newnode;
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
    newnode->prev=NULL;
    temp=listptr;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;

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
    newnode->prev=NULL;
    cout<<"enter node";
    cin>>y;
    while(i!=y-1)
    {
        temp=temp->next;
        i++;
    }
    temp->next->prev=newnode;
    newnode->next=temp->next;
    temp->next=newnode;
    newnode->prev=temp;

}
void List::deletionbeg()
{
    temp=listptr;
    listptr=listptr->next;
    listptr->prev=NULL;
    delete(temp);
}
void List::deletion_end()
{
    temp=listptr;
    Node*q;
    while(temp->next->next=NULL)
    {
        temp=temp->next;
    }
    q=temp->next;
    temp->next=NULL;
    q->prev=NULL;
    delete(q);
}
void List::deletion_mid()
{
    int y,i;
    temp=listptr;
    Node*q;
    cout<<"enter positon";
    cin>>y;
    for(i=0;i<y-1;i++)
    {
        temp=temp->next;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    delete(temp);
}
void List::concat(List o,List j)
{
    temp=o.listptr;
    while (temp->next!=NULL)
    {
        temp=temp->next;

    }
    temp->next=j.listptr;
    j.listptr->prev=temp;

}
void List::reverse()
{
    Node *temp = listptr;
    Node*q;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    listptr=temp;
    while (temp->prev !=NULL)
    {
        q=temp->prev;
        temp->next=q;
        q->prev=temp;
        temp=q;
    }
    
}
int main()
{
    int p=1,ch;
    List l;
    List u;
    while (p==1)
    {
        cout<<"\n Enter choice \n 1-create\n 2-display\n 3-Insertion At Beginning\n 4-Insertion At end\n 5-insertion At mid";
        cout<<"\n 6-Deletion At Beginning\n 7-Deletion At end\n 8-Deletion At mid \n 9-Reverse \n 10- Concat";
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
