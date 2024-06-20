#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*first=NULL,*second=NULL,*third=NULL;
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
void merge(struct node *p,struct node *q)
{
    struct node *last;
    //first node creation
    if(p->data < q->data)
    {
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    //loop will run till anyone of the node become null
    while(p && q)
    {
        if(p->data < q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }

    }
    if(p)
        last->next=p;
    if(q)
        last->next=q;
}
void display( struct node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

int main()
{
    int a[]={3,5,5,5,8,8,9,10};
    create(a,8);
    int b[]={3,5,5,5,8,8,9,10};
    create1(b,8);
    merge(first,second);
    display(first);
}