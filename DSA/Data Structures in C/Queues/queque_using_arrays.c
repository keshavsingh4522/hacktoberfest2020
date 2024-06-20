#include <stdio.h>
#include <stdlib.h>
struct queue{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct queue *q,int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=(int *)malloc(q->size*sizeof(int));
}
void enqueue(struct queue *q,int x){
    if(q->rear==q->size){
        printf("queue is full\n");
    }
    else{
        q->Q[q->rear]=x;
        q->rear++;
    }
}
int dequeue(struct queue *q){
    int x=-1;
    if(q->front==q->rear){
        printf("queue is empty\n");
    }
    else{
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}
int QueueRearEle(struct queue q){
    if(1){
        return q.Q[q.rear];
    }
    else{
        return 0;
    }
}
void display(struct queue q ){
    while(q.front!=q.rear){
        printf("%d ",q.Q[q.front]);
        q.front++;
    }
}
int main() {
    struct queue q;
    create(&q,7);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,10);

    dequeue(&q);
    dequeue(&q);

    display(q);
    printf("%d",QueueRearEle(q));
}
