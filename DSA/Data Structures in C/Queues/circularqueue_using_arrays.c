#include <stdio.h>
#include <stdlib.h>
struct queue{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct queue *q,int siz){
    q->front=q->rear=0;
    q->size=siz;
    q->Q=(int *)malloc(q->size*sizeof(int *));
}
void enqueue(struct queue *q,int x){

    if((q->rear+1)%q->size==q->front){
        printf("queue is full\n");
    }
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[(q->rear+1)%q->size]=x;
    }
}
int dequeue(struct queue *q){
    int x=-1;
    if(q->front==q->rear){
        printf("quque is empty\n");
    }
    else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}
void Display(struct queue q)
{
    int i=q.front+1;
    do
    {
        printf("%d ",q.Q[i]);
        i=(i+1)%q.size;
    }while(i!=(q.rear+1)%q.size);
    printf("\n");
}
int main(){
    struct queue q;
    create(&q,6);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);
    Display(q);
    printf("%d ",dequeue(&q));

}