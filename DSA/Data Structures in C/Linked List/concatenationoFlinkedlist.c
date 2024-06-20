#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*first=NULL,*second=NULL;
void create(int A[],int n){
    int i;
    struct node *t,*last;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void create1(int A[],int n){
    int i;
    struct node *t,*last;
    second=(struct node *)malloc(sizeof(struct node));
    second->data=A[0];
    second->next=NULL;
    last=second;
    for(int i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void concatenate(struct node *p,struct node *q){
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;
}
void display( struct node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

int main()
{
    int a[]={3,5,5,5,8,8,9,3,4,10};
    create(a,10);
    int b[]={3,5,5,5,8,8,9,3,4,10};
    create1(b,10);
    concatenate(first,second);
    display(first);
}