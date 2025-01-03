
// Implementation of Circular Queue using array
#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 5

class Queue{
    public:
        int data[MAX_SIZE];
        int front;
        int rear;
};

void BuildQueue(Queue* &q1)
{
    q1 = new Queue();
    q1->rear = -1;
    q1->front = -1;
}

bool isEmpty(Queue* &q1)
{
    if(q1 -> front == -1  && q1->rear == -1)
    {
        return true;
    }
    else{
        return false;
    }
}

bool isFull(Queue* &q1)
{
    if((q1 ->rear +1)%MAX_SIZE == q1->front)
    {
        return true;
    }
    else{
        return false;
    }
}

void Enqueue(Queue* &q1)
{
    if(!isFull(q1))
    {
        if(q1->front == -1 && q1->rear == -1)
        {
            q1->front = q1->rear = 0;
        }
        else{
            q1->rear = (q1->rear+1)%(MAX_SIZE);
        }
        int val;
        cout<<"Enter the value to be enqueued:";
        cin>>val;
        q1->data[q1-> rear] = val;
    }
    else{
        cout<<"ERROR! Overflow\n";
    }
}

void Dequeue(Queue* &q1)
{
   if(!isEmpty(q1))
   {
       if(q1->front == q1->rear)
       {
           cout<<"The dequeued value is:"<<q1->data[q1->front]<<endl;
           q1->front = q1->rear = -1;
       }
       else{
           cout<<"The dequeued value is:"<<q1->data[q1->front]<<endl;
           q1->front = (q1->front +1)%(MAX_SIZE);
       }
   }
   else{
       cout<<"ERROR! Underflow\n";
   }
}

int main()
{
    Queue *q1;
    BuildQueue(q1);
    cout<<isEmpty(q1)<<endl;
    cout<<isFull(q1)<<endl;
    Enqueue(q1);
    Enqueue(q1);
    Dequeue(q1);
    Dequeue(q1);
    cout<<isEmpty(q1)<<endl;
    Enqueue(q1);
    cout<<isEmpty(q1)<<endl;
    Enqueue(q1);
    Enqueue(q1);
    cout<<isFull(q1)<<endl;
    Dequeue(q1);
    Dequeue(q1);
    Dequeue(q1);
    cout<<isEmpty(q1)<<endl;
    return 0;
}
