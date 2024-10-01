/*
     hare krishna hare krishna krishna krishna hare hare
     hare rama hare rama rama rama hare
*/

//// happy coding ////
//// chant hare krishna /////
//// ritik dagar ///////

#include<bits/stdc++.h>
using namespace std;

class node{
	public:
		int data;
		node *prev;
		node *next;
		node()
		{
			data=0;
			prev=next=NULL;
		}
		node(int n)
		{
			data=n;
			prev=NULL;
			next=NULL;
		}
};
int num,val;
node *start = NULL;
node *createll(node *);
node *display(node *);
node *insertbeg(node *);
node *insertend(node *);
node *insertbefore(node *);
node *insertafter(node *);
node *deletebeg(node *);
node *deleteend(node *);
node *deletenode(node *);
node *deleteafter(node *);
node *deletebefore(node *);
node *deletelist(node *);
node *sortll(node *);
int main()
{
	int option;
	cout<<"hare krishna hare krishna\nkrishna krishna hare hare\nhare rama hare rama\nrama rama hare hare\n";
	cout<<"representation of doubly linked list\n";
	do{
		cout<<"\n\n *******MAIN MENU*******";
		cout<<"\n 1:  Create a list ";
		cout<<"\n 2:  Display the list ";
		cout<<"\n 3:  Add a node at the begining";
		cout<<"\n 4:  Add a node at the end";
		cout<<"\n 5:  Add a node before a given node";
		cout<<"\n 6:  Add a node after a given node";
		cout<<"\n 7:  delete a node from the begining";
		cout<<"\n 8:  delete a node from the end";
		cout<<"\n 9:  delete a given node";
		cout<<"\n 10: delete a node after given node";
		cout<<"\n 11: delete a node before given node";
		cout<<"\n 12: delete entire list";
		cout<<"\n 13: sort the list";
		cout<<"\n 14: exit\n";
		cin>>option;
		switch(option)
		{
			case 1:
				start= createll(start);
				cout<<"\n linked list created";
				break;
			case 2:
				start= display(start);
				break;
		    case 3:
		    	start= insertbeg(start);
		    	break;
		    case 4:
		    	start= insertend(start);
		    	break;
		    case 5:
		    	start= insertbefore(start);
		    	break;
		    case 6:
		    	start= insertafter(start);
		    	break;
		    case 7:
		    	start= deletebeg(start);
		    	break;
		    case 8:
		    	start= deleteend(start);
		    	break;
		    case 9:
		    	start= deletenode(start);
		    	break;
		    case 10:
		    	start= deleteafter(start);
		    	break;
		    case 11:
		    	start=deletebefore(start);
		    	break;
		    case 12:
		    	start= deletelist(start);
		    	cout<<"\n linked list deleted";
		    	break;
		    case 13:
		    	start= sortll(start);
		    	break;
		     
		}
	}while(option!=14);
	
	return 0;
}

node* createll(node *start)
{
	node* nn,*p;
	int num;
	cout<<"\nenter -1 to end\n";
	cin>>num;
	while(num!=-1)
	{
		nn=new node(num);
		if(start==NULL)
		{		
		    start=nn;
		}
		else
		{
			p=start;
			while(p->next!=NULL)
				p=p->next;
			p->next=nn;
			nn->prev=p;
		}
		cin>>num;
	}
	return start;
}
node *display(node* start)
{
	node *t=start;
	while(t!=NULL)
	{
		cout<<t->data<<" -> ";
		t=t->next;
	}
	cout<<"NULL\n";
	return start;
}

node *insertbeg(node *start)
{
    cin>>num;
	node *nn= new node(num);
	nn->next=start;
	start=nn;
	return start;
}

node *insertend(node *start)
{
	cin>>num;
	node *nn=new node(num);
	node *p=start;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=nn;
	nn->prev=p;
	
	return start;	
}
node *insertbefore(node *start)
{
   cin>>num>>val;
   node *n= new node(num);
   node *p=start;
   while(p->data!=val)
   p=p->next;
   n->prev=p->prev;
   n->next=p;
   p->prev->next=n;
   p->prev=n;
   return start;	
}

node *insertafter(node *start)
{
	cin>>num>>val;
	node *nn=new node(num);
	node *p= start;
	while(p->data!=val)
	{
		p=p->next;
	}
    nn->next=p->next;
    nn->prev=p;
    p->next->prev=nn;
    p->next=nn;

return start;
}

node *deletebeg(node *start)
{
	node *nn;
	nn= start;
	start=nn->next;
	start->prev=NULL;
	free(nn);
	
	return start;
}

node *deleteend(node *start)
{
	node *nn=start;
	while(nn->next!=NULL)
	{
		nn=nn->next;
	}
    nn->prev->next=NULL;
    free(nn);
	return start;
}

node *deletenode(node *start)
{
	cin>>val;
	node *p=start;
while(p->data!=val)
{
	p=p->next;
}
p->prev->next= p->next;
free(p);

return start;
	
}

node *deleteafter(node *start)
{
	node *p=start,*t;
	int num;
	cin>>num;
	while(p->data!=num)
	{
		p=p->next;
	}
	t=p->next;
	p->next=t->next;
	t->next->prev=p;
	free(t);
	return start;
}
node *deletebefore(node *start)
{
	node *p=start;
	cin>>num;
	while(p->data!=num)
	p=p->next;
	node *t=p->prev;
	if(t==start)
	start=deletebeg(start);
	else{
	p->prev=t->prev;
	t->prev->next=p;
}
	free(t);
	return start;
}
node *deletelist(node *start)
{
	node *n=start;
	while(n!=NULL)
	{
		start= deletebeg(start);
		n=start;
	}
	
	return start;
}

node *sortll(node *start)
{
	node *p1,*p2;
	int t;
	p1=start;
	while(p1->next!=NULL)
	{
		p2=p1->next;
		while(p2!=NULL)
		{
			if(p1->data>p2->data)
			{
				t=p1->data;
				p1->data=p2->data;
				p2->data=t;
			}
			p2=p2->next;
		}
		p1=p1->next;
	}
	return start;
}
