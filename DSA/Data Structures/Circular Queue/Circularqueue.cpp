#include<iostream>
using namespace std;
class CircularQueue
{   private:
    int *a,front,rear,size;
    public:
    CircularQueue(int size)
    {
        this->size =size;
        a = new int [size]; 
        front = rear = -1;
    }

    void enqueue(int x)
    {
         if((rear+1)%size == front)
         cout<<"Overflow!!!\n";
         else if(front==-1)
         {
               front  = rear = 0;
               a[front] = x;
         }
         else
         {    rear = (rear+1)%size;
             a[rear] = x;
           
         }
    }

    void dequeue()
    {
        if((front)%size == (rear)%size || front ==-1 )
        cout<<"Underflow!!!\n";
        else
        {
            front = (front+1)%size;
        }
    }

    bool isEmpty()
    {
        return (front+1)%size==(rear+1)%size;
    }
    bool isFull()
    {
        return (rear+1)%size == front;
    }
    void display()
    {
         int temp = front;
            do 
             {cout<<a[temp]<<" ";
             temp = (temp+1)%size;}while(temp!=(rear+1)%size);
   
    }
    int peek()
    {
        if(isEmpty())
        return -1;
        return a[front];
    }
};
int main()
{
       CircularQueue s(5);
       int choice,x;
       while(true)
       {
          cout<<"\nCircular Queue Menu Driven Program:\n1.Enqueue\n2.Dequeue\n3.IsEmpty?\n4.IsFull?\n5.Peek\n6.Display\n7.Exit\n";
          cin>>choice;
          switch(choice)
          {
              case 1:
              cout<<"\nEnter Element to be inserted\n";
              cin>>x;
              s.enqueue(x);
              break;

              case 2:
              cout<<"Deleting one Element\n";
              s.dequeue();
              break;

              case 3:
              if(s.isEmpty())
              cout<<"Queue is empty\n";
              else
              cout<<"Queue is not empty\n";
              break;

              case 4:
              if(s.isFull())
              cout<<"Queue is full\n";
              else
              cout<<"Queue is not full\n";
               break;

               case 5:
               if(s.peek()==-1)
               cout<<"Queue is Empty\n";
               else
               cout<<"Current elem is "<<s.peek()<<"\n";
               break;

               case 6 :
               cout<<"Queue looks like:\n";
               s.display();
               cout<<"\n";
               break;

               case 7 :
               cout<<"Exiting\n";
               exit(1);
               break;
 
               default: 
               cout<<"Wrong choice Entered\n";
               break;

          }
       }
}