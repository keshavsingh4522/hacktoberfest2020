#include <iostream>
#include <algorithm>

using namespace std;
#define MAX_SIZE 100
int Q[MAX_SIZE];
int rear = -1, front = -1;

void enqueue(int x); //to add member to queue
void dequeue();      //to delete member from queue
bool IsFull();       //to check if the queue(array) is full
bool IsEmpty();      //to check if the queue (array) is empty
int Peek();          //to see the front-most element
void print();        //to print the queue

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    print();
    dequeue();
    dequeue();
    print();
    cout<<endl;
    return 0;
}

void print()
{
    cout<<"\nCurrent queue is: ";
    for(int i = front; i<=rear; i++)
    {
        cout<<Q[i]<<" ";
    }
}

bool IsEmpty()
{
    if((rear==-1)&&(front==-1))
    return true;
    else
    return false;
}

bool IsFull()
{
    if(rear == INT_MAX-1)
    return true;
    else
    return false;
}

void enqueue(int x)
{
    if(IsFull())
    {
        return;
    }
    else if(IsEmpty())
    {
        front++;
        rear++;
        Q[rear] = x;
    }
    else{
        rear++;
        Q[rear] = x;
    }   
}

void dequeue()
{
    if(IsEmpty())
    {
        cout<<"\nQueue is empty, nothing to dequeue.";
        return;
    }
    else if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    front++;
}
