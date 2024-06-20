#include<stdio.h>
#include <stdlib.h>
#ifndef QueueCpp_h
#define QueueCpp_h
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};
struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};
void create(struct Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=0;

    q->Q=(struct Node **)malloc(q->size*sizeof(struct
    Node *));
}
void enqueue(struct Queue *q,struct Node *x)
{
    if((q->rear+1)%q->size==q->front)
    printf("Queue is Full");
    else
    {
    q->rear=(q->rear+1)%q->size;
    q->Q[q->rear]=x;
    }
}
struct Node * dequeue(struct Queue *q)
{
    struct Node* x=NULL;
    if(q->front==q->rear)
    printf("Queue is Empty\n");
    else
    {
    q->front=(q->front+1)%q->size;
    x=q->Q[q->front];
    }
return x;
}
int isEmpty(struct Queue q)
{
    return q.front==q.rear;
}
#endif