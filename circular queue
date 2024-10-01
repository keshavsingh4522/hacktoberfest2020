#include<iostream>
using namespace std;
class queue
{
    int *arr;
    int front,rear,size;
    public:
    void init(int n)
    {
        size=n;
        arr=new int[n];
        front=rear=-1;
    }
    int isempty()
    {
        return rear==-1;
    }
    int isfull()
    {
        return (((rear==size-1)&&front==0)|| front==rear+1);
    }
    void enqueue(int data)
    {
        if(isfull())
        return;
        else
        {
            if(front==-1)
            front=0;
            if(rear!=size-1)
            rear++;
            else
            rear=0;
            arr[rear]=data;
        }
    }
    int dequeue()
    {
        if(isempty())
        return 5674;
        else
        {
            int temp=arr[front];
            if(front==rear)
            front=rear=-1;
            else if(front!=size-1)
            front++;
            else front=0;
            return temp;
        }
    }

};
int main()
{
    queue q;
    q.init(6);
    q.enqueue(45);
    q.enqueue(60);
    q.enqueue(34);
    q.enqueue(55);
    q.enqueue(90);
    q.enqueue(76);
    cout<<"Deleted item:"<<q.dequeue()<<endl;
    cout<<"Deleted item:"<<q.dequeue()<<endl;
    cout<<"Deleted item:"<<q.dequeue()<<endl;
    return 0;
}
