#include <iostream>
#include <algorithm>

using namespace std;

class node
{
public:
    int data;
    node *next;
};

node *front = NULL;
node *rear = NULL;

void enqueue(int x);    //to add member from queue
void dequeue();         //to delete member from queue
int peek();             //to see front-most element
bool IsEmpty();         //to check if queue is empty
void print();           //to print queue

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    print();
    dequeue();
    print();
    dequeue();
    print();
    cout << "\nFirst element in queue is: " << peek();
    cout << endl;
    return 0;
}

bool IsEmpty()
{
    if ((rear == NULL) && (front == NULL))
    {
        return true;
    }
    else
        return false;
}

void enqueue(int x)
{
    node *newnode = new node;
    newnode->data = x;
    newnode->next = NULL;
    if (IsEmpty())
    {

        front = newnode;
        rear = newnode;
        return;
    }
    node *temp = front;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    rear = newnode;
}

void dequeue()
{
    if (IsEmpty()) //queue empty
    {
        cout << "\nNo element present to delete.";
        return;
    }
    else if (front == rear) //one element present
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        node *temp = front;
        front = temp->next;
        free(temp);
    }
}

void print()
{
    if (IsEmpty())
    {
        cout << "\nQueue empty.";
        return;
    }
    node *temp = front;
    cout << "\nCurrent Queue is: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int peek()
{
    if (IsEmpty())
    {
        cout << "\nQueue empty";
        return 0;
    }
    node *temp = front;
    int a = temp->data;
    return a;
}
