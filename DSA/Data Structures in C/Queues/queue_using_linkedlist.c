#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;
void enqueue(int x){
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node *));
    t->data=x;
    t->next=NULL;
    if(front==NULL){
        front=rear=t;
    }
    else{
        rear->next=t;
        rear=t;
    }
}
int dequeue(){
    int x=-1;
    struct node *t;
    if(front==NULL){
        printf("queue is empty");
    }
    else{
        x=front->data;
        t=front;
        front=front->next;
        free(t);
    }
    return x;
}
void display(){
    struct node *t;
    t=front;
    while(t!=NULL){
        printf("%d",t->data);
        t=t->next;
    }
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    display();
    dequeue();
    dequeue();
    printf("\n");
    display();
}