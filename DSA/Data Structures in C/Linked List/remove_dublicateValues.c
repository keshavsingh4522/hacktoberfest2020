#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*first=NULL,*last;
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
void remove_dublicateElements(struct node *p){
    struct  node *q;
    q=p->next;
    //ye traversing if for aaju baaju element
    while(q!=NULL){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else if(p->data==q->data) {
            p->next = q->next;
            free(q);
            q = p->next;
        }
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
    remove_dublicateElements(first);
    display(first);
}