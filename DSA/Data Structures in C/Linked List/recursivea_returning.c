#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*first=NULL,*tail=NULL;
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
void recursive_reverse(struct node *p,struct node *q){
    if(p!=NULL){
        recursive_reverse(p->next,p);
        p->next=q;
    }
    else{
     first=q;
    }
}
void display( struct node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

int main()
{
    struct node *temp;
    int a[]={3,5,5,5,8,8,9,3,4,10};
    create(a,10);
    recursive_reverse(first,tail);
    display(first);
}