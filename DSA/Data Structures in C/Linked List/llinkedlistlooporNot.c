#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
        if(i==n-1){
            t->next=first;
        }
    }
}
int isloop(struct node *p){
    struct node *f,*s;
    f=s=p;
    do {
        f=f->next;
        s=s->next;
        if(s->next!=NULL) {
            s = s->next;
        }
        else{
            break;
        }
    }while (f != s);
    return f==s?true:false;
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
    int check=isloop(first);
    printf("%d ",check);
    int check1=isloop(second);
    printf("%d",check1);

}