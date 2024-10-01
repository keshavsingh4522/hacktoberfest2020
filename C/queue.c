
#include <stdio.h>
#define MAX_SIZE 101

int queue[MAX_SIZE];
int front=-1,rear=-1;

void enqueue(int x){
    if(rear==-1 && front==-1){
        rear++;
        front++;
        queue[rear]=x;
    }
    else if(rear==MAX_SIZE-1){
        printf("\nQueue Overflow!\n");
    }
    else{
        rear++;
        queue[rear]=x;
    }
    
}

void dequeue(){
    if(rear==-1 && front==-1){
        printf("\nQueue is Empty!\n");
    }
    else{
    front++;
    }
}

void print(){
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main()
{
    enqueue(5);
    enqueue(4);
    enqueue(3);
    enqueue(1);
    print();
    dequeue();
    printf("\nAfter dequeue\n");
    print();
    
    
    
   
    
    
    //wap implement a queue
    //wap to reverse a queue
    //implement a stack using queue operation
    //interleave the first part of queue with the second part
    //implemenation of queue using stack
    
    
    return 0;
}

