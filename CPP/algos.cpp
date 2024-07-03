#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};


void pushElement(Node** head, int data_val){
    Node* temp_node=new Node();

    temp_node->data=data_val;
    temp_node->next=*head;
    *head=temp_node;
}

bool searchElement(Node* head, int x)
{
	Node* current = head;
	while (current != NULL)
	{
		if (current->data == x)
			return true;
		current = current->next;
	}
	return false;
}

void deleteElement(Node** head_ref, int key)
{
    Node* temp = *head_ref;
    Node* prev = NULL;

    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        delete temp;
        return;
    }
       else
    {
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;

    delete temp;
    }
}


void printList(Node* head){
    Node* temp_node=head;

    while(temp_node!=NULL){
        cout<<temp_node->data<<" ";
        temp_node=temp_node->next;
    }
}

void newList(Node* head){

}

int main(){

    Node* head = NULL;
    pushElement(&head, 10);
	pushElement(&head, 30);
	pushElement(&head, 11);

    int key;
    do{
        cout<<"\n---------------------------\n";
        cout<<"1. Push a new element\n";
        cout<<"2. Search for an element\n";
        cout<<"3. Delete an element\n";
        cout<<"4. Print\n";
        cout<<"5. Exit\n";
        cout<<"---------------------------";
        cout<<"\n";

        cout<<"Enter The option: ";
        cin>>key;

        switch (key)
        {
        case 1:
            int x;
            cout<<"Enter data value: ";
            cin>>x;
            pushElement(&head, x);
            break;
        case 2:
            int y;
            cout<<"Enter the element you need to search: \n";
            cin>>y;
            searchElement(head, y)? cout<<"The element exists in the linked list" : cout<<"No, the element doesn't exist";
            break;
        case 3:
            int z;
            cout<<"Enter the element you want to delete: ";
            cin>>z;
            deleteElement(&head, z);
            break;
        case 4:
            printList(head);
            break;
        case 5: exit(0);
        default: cout<<"\a";
    }
    }while(key!=5);

}
