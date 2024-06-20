#include <stdio.h>
#include <stdlib.h>
struct queue{
    int size_linked;
    int front;
    int rear;
    int *Q;
};
void createlinkedlst(struct queue *q,int size)
{
    q->size_linked=size;
    q->front=q->rear=0;
    q->Q=(int *)malloc(q->size_linked*sizeof(int));
}
void enqueue(struct queue *q,int x){
    if(q->rear==q->size_linked){
        return;
    }
    else{
        q->Q[q->rear]=x;
        q->rear=q->rear+1;
    }
}
int dequeue(struct queue *q){
    int x=-1;
    if(q->front==q->rear){
        return -1;
    }
    else{
        x=q->Q[q->front];
        for(int i=0;i<q->rear-1;i++){
            q->Q[i]=q->Q[i+1];
        }
        q->rear--;
    }
    return x;
}
int isqueueFull(struct queue q){
    if(q.rear==q.size_linked){
        return 1;
    }
    else{
        return 0;
    }
}
int isqueueempty(struct queue q){
    if(q.front==q.rear){
        return 1;
    }
    else{
        return 0;
    }
}
int QueueRearEle(struct queue q){
    if(!isqueueempty(q)){
        return q.Q[q.rear];
    }
    else{
        return 0;
    }
}
int QueueFrontEle(struct queue q){
    if(!isqueueempty(q)){
        return q.Q[q.front];
    }
    else{
        return 0;
    }
}
void displayqueue(struct queue q ){
    while(q.front!=q.rear){
        printf("%d ",q.Q[q.front]);
        q.front++;
    }
}
int coun(struct queue q){
    int counter=0;
    while(q.front!=q.rear){
        counter++;
        q.front++;
    }
    return counter;
}
int order(struct queue q){
    int count=0;
    int a=coun(q);
    int min=q.Q[q.front];
    while(q.front!=q.rear){
        if(min<=q.Q[q.front]){
            min=q.Q[q.front];
            count++;
        }
        else{
            break;
        }
        q.front++;
    }
    if(count==a){
        return 1;
    }
    else{
        return 0;
    }

}
int main() {
    struct queue q;
    createlinkedlst(&q,6);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);
    enqueue(&q,60);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    enqueue(&q,65);
    enqueue(&q,70);
    enqueue(&q,80);
    displayqueue(q);
    printf("\n%d",isqueueFull(q));
    printf("\n%d",isqueueempty(q));
    printf("\n%d",coun(q));
    printf("\n%d",order(q));



}
