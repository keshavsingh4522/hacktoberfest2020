#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node *next;
		node(int data)
		{
			this->data = data;
			this->next = NULL;
		}
};

void insertAtHead(node **head, int x)
{
	//cout<<"inserted";
	if(*head == NULL)
	{
		*head = new node(x);
		return;
	}
    node * n = new node(x);
    n->next = *head;
    *head = n;
}

void insertInMiddle(node **head, int x, int pos)
{
	if(pos == 0)
	{
		insertAtHead(&(*head), x);
		return;
	}
	else
	{
		node *temp = *head;
		for(int i=1;i<pos-1;i++)
		{
			temp = temp->next;
		}
		node *n = new node(x);
		n->next = temp->next;
		temp->next = n; 
	}
}

void printList(node * head)
{
	while(head != NULL)
	{
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<endl;
}

int main()
{
	node *head = NULL;
	insertAtHead(&head, 3);
	insertAtHead(&head, 6);
	insertAtHead(&head, 9);
	insertAtHead(&head, 12);
	printList(head);
	insertInMiddle(&head, 18, 2);
	printList(head);
	return 0;
}
