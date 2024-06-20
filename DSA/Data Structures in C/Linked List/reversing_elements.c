#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*first=NULL;
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
void reversing_elements(struct node *p,int x){
    int arr[x];
    int i=0;
    while(p!=NULL){
        arr[i]=p->data;
        i++;
        p=p->next;
    }
    struct node *q=first;
    for(int i=x-1;i>=0;i--){
        q->data=arr[i];
        q=q->next;
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
    reversing_elements(first,10);
    display(first);
}