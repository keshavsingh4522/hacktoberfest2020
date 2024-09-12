#include<iostream>
using namespace std;

class Node
{
	public :
		int data;
		Node *next;
		
	Node(int data)
	{
		this -> data = data;
		next =  NULL;
	}
};

Node* takeInput()
{
	int data;
	cin>>data;
	Node *head = NULL;
	Node *tail= head;
	while(data!=-1)
	{
		Node *newNode = new Node(data);
		if(head==NULL)
		{
			head=newNode;
			tail= head;
		}
		
		else
		{
		tail->next=newNode;
		newNode->next= NULL;
		tail=tail->next;
		}
	cin>>data;
	}
	return head;
}
 
Node * AppendNode(Node* head)
{
	int N;
	cin>>N;
	int c=0;
	if(head==NULL)
	{
		return head;
	}
	else
	{
		Node *temp=head;
		Node *tail=head;
		while(temp!=NULL)
		{
			tail=temp;
			temp=temp->next;
			c++;
			
		}
		temp = head;
		
		for(int i=0;i<c-N-1;i++)
		temp=temp->next;
		
		tail->next=head;
		head= temp->next;
		temp->next=NULL;
		
		return head;
		
	}
 }
 
 void printNode(Node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}
int main()
{
	Node *head = takeInput();
	head=AppendNode(head);
	printNode(head);
	delete head;
	return 0;
}
