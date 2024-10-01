/*
     hare krishna hare krishna krishna krishna hare hare
     hare rama hare rama rama rama hare
*/

//// happy coding ////
//// chant hare krishna /////
//// rk dagar ///////

#include<bits/stdc++.h>
using namespace std;

class node{
	public:
		int data;
		node *next;
		node(int n)
		{
			data=n;
			next=NULL;
		}
			node()
		{
			data=0;
			next=NULL;
		}
};

node *start = NULL;
node *createll(node *);
node *display(node *);
int main()
{
	int option;
	do{
		cout<<"\n\n *******MAIN MENU*******";
		cout<<"\n 1:  Create a header linked list ";
		cout<<"\n 2:  Display the header linked list ";
		cout<<"\n 3:  exit\n";
		cin>>option;
		switch(option)
		{
			case 1:
				start= createll(start);
				cout<<"\nheader linked list created";
				break;
			case 2:
				start= display(start);
				break;

		}
	}while(option!=3);
	
	return 0;
}

node* createll(node *start)
{
	node* n,*p;
	int num;
	cout<<"\nenter -1 to end\n";
	cin>>num;
	while(num!=-1)
	{
		n=new node(num);
		if(start==NULL)
		{		
		    start = new node();
		    start->next=n;
		}
		else
		{
			p=start;
			while(p->next!=NULL)
				p=p->next;
			p->next=n;
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

