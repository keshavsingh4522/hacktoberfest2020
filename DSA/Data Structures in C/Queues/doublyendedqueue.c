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
    q->front=0;
    q->rear=-1;
    q->Q=(int *)malloc(q->size*sizeof(int));
}
void enqueue(struct queue *q,int x){
    if(q->rear==q->size-1){
        printf("queue is full\n");
    }
    else{
        q->rear++;
        q->Q[q->rear]=x;
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
void DEenqueue(struct queue *q,int x){
    printf("\nType 1 to insert from front\nType 2 to insert from rear");
    int num;
    scanf("%d",&num);
    switch (num) {
        case 1:
            if(q->front==-1){
                printf("\nqueue is full from front\n");
            }
            else{
                q->front--;
                q->Q[q->front]=x;
            }
            break;

        case 2:
            if(q->rear==q->size-1){
                printf("\nqueue is full from the rear\n");
            }
            else{
                q->rear++;
                q->Q[q->rear]=x;
            }
            break;
        default:
            printf("\nwrong input\n");
            break;
    }
}
void display(struct queue q ){
    do{
        printf("%d ",q.Q[q.front]);
        q.front++;
    }while(q.front!=q.rear+1);
}
int main() {
    struct queue q;
    create(&q,8);
    enqueue(&q,10);//0
    enqueue(&q,20);//1
    enqueue(&q,30);//2
    enqueue(&q,10);//3
    enqueue(&q,20);//4
    enqueue(&q,30);//5
    enqueue(&q,30);//6
    display(q);
    dequeue(&q);//0= null front==1
    DEenqueue(&q,14);
    DEenqueue(&q,16);
    display(q);

}
/*
#include<stdio.h>
#include<process.h>
#define MAX 30

typedef struct dequeue
{
	int data[MAX];
	int rear,front;
}dequeue;

void initialize(dequeue *p);
int empty(dequeue *p);
int full(dequeue *p);
void enqueueR(dequeue *p,int x);
void enqueueF(dequeue *p,int x);
int dequeueF(dequeue *p);
int dequeueR(dequeue *p);
void print(dequeue *p);

void main()
{
	int i,x,op,n;
	dequeue q;

	initialize(&q);

	do
	{
		printf("\n1.Create\n2.Insert(rear)\n3.Insert(front)\n4.Delete(rear)\n5.Delete(front)");
		printf("\n6.Print\n7.Exit\n\nEnter your choice:");
		scanf("%d",&op);

		switch(op)
		{
			case 1: printf("\nEnter number of elements:");
					scanf("%d",&n);
					initialize(&q);
					printf("\nEnter the data:");

					for(i=0;i<n;i++)
					{
						scanf("%d",&x);
						if(full(&q))
						{
							printf("\nQueue is full!!");
							exit(0);
						}
						enqueueR(&q,x);
					}
					break;

			case 2: printf("\nEnter element to be inserted:");
					scanf("%d",&x);

					if(full(&q))
					{
						printf("\nQueue is full!!");
						exit(0);
					}

					enqueueR(&q,x);
					break;

			case 3: printf("\nEnter the element to be inserted:");
					scanf("%d",&x);

					if(full(&q))
					{
						printf("\nQueue is full!!");
						exit(0);
					}

					enqueueF(&q,x);
					break;

			case 4: if(empty(&q))
					{
						printf("\nQueue is empty!!");
						exit(0);
					}

					x=dequeueR(&q);
					printf("\nElement deleted is %d\n",x);
					break;

			case 5: if(empty(&q))
					{
						printf("\nQueue is empty!!");
						exit(0);
					}

					x=dequeueF(&q);
					printf("\nElement deleted is %d\n",x);
					break;

			case 6: print(&q);
					break;

			default: break;
		}
	}while(op!=7);
}

void initialize(dequeue *P)
{
	P->rear=-1;
	P->front=-1;
}

int empty(dequeue *P)
{
	if(P->rear==-1)
		return(1);

	return(0);
}

int full(dequeue *P)
{
	if((P->rear+1)%MAX==P->front)
		return(1);

	return(0);
}

void enqueueR(dequeue *P,int x)
{
	if(empty(P))
	{
		P->rear=0;
		P->front=0;
		P->data[0]=x;
	}
	else
	{
		P->rear=(P->rear+1)%MAX;
		P->data[P->rear]=x;
	}
}

void enqueueF(dequeue *P,int x)
{
	if(empty(P))
	{
		P->rear=0;
		P->front=0;
		P->data[0]=x;
	}
	else
	{
		P->front=(P->front-1+MAX)%MAX;
		P->data[P->front]=x;
	}
}

int dequeueF(dequeue *P)
{
	int x;

	x=P->data[P->front];

	if(P->rear==P->front)	//delete the last element
		initialize(P);
	else
		P->front=(P->front+1)%MAX;

	return(x);
}

int dequeueR(dequeue *P)
{
	int x;

	x=P->data[P->rear];

	if(P->rear==P->front)
		initialize(P);
	else
		P->rear=(P->rear-1+MAX)%MAX;

	return(x);
}

void print(dequeue *P)
{
	if(empty(P))
	{
		printf("\nQueue is empty!!");
		exit(0);
	}

	int i;
	i=P->front;

	while(i!=P->rear)
	{
		printf("\n%d",P->data[i]);
		i=(i+1)%MAX;
	}

	printf("\n%d\n",P->data[P->rear]);
}*/