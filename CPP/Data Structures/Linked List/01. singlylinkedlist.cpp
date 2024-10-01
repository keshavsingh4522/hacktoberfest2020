
//// happy coding ////
//// chant hare krishna /////
//// rk dagar ///////

#include<bits/stdc++.h>
using namespace std;

class node{
	public:
		int data;
		node *next;
};

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
node *deletelist(node *);
node *sortll(node *);
int main()
{
	int option;
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
		cout<<"\n 11: delete entire list";
		cout<<"\n 12: sort the list";
		cout<<"\n 13: exit\n";
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
		    	start= deletelist(start);
		    	cout<<"\n linked list deleted";
		    	break;
		    case 12:
		    	start= sortll(start);
		    	break;
		     
		}
	}while(option!=13);
	
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
		nn=new node();
		nn->data=num;
		nn->next=NULL;
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
	node *nn= new node();
	int num;
	cin>>num;
	nn->data=num;
	nn->next=start;
	start=nn;
	
	return start;
}

node *insertend(node *start)
{
	node *nn=new node();
	node *p=start;
	int num;
	cin>>num;
	nn->data=num;
	nn->next=NULL;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=nn;
	
	
	return start;
	
	
}
node *insertbefore(node *start)
{
	node *nn= new node();
	node *p=start;
	node *preptr;
	int num,val;
	cin>>num>>val;
	nn->data=num;
	while(p->data!=val)
	{
		preptr=p;
		p=p->next;
	}
	preptr->next=nn;
	nn->next=p;
	
	return start;
	
}

node *insertafter(node *start)
{
	node *nn=new node();
	node *p= start,*pre=start;
	int num,val;
	cin>>num>>val;
	nn->data=num;
	while(pre->data!=val)
	{
		pre= p;
		p=p->next;
	}
nn->next=p;
pre->next=nn;

return start;
}

node *deletebeg(node *start)
{
	node *nn;
	nn= start;
	start=nn->next;
	free(nn);
	
	return start;
}

node *deleteend(node *start)
{
	node *nn=start,*p;
	while(nn->next!=NULL)
	{
		p=nn;
		nn=nn->next;
	}
	p->next=NULL;
	free(nn);
	
	return start;
}

node *deletenode(node *start)
{
	int val;
	cin>>val;
	node *p=start,*pre;
	while(p->data==val) 
	{
		start= deletebeg(start);
	return start;
}
while(p->data!=val)
{
	pre=p;
	p=p->next;
}
pre->next=p->next;
free(p);

return start;
	
}

node *deleteafter(node *start)
{
	node *nn,*p=start;
	nn=start;
	int num;
	cin>>num;
	while(p->data!=num)
	{
		p=nn;
		nn=nn->next;
	}
	p->next=nn->next;
	free(nn);
	
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

