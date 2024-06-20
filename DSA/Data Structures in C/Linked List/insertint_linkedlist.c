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
void display( struct node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}
int count1(struct node *p){
    int count=0;
    while(p){
        count++;
        p=p->next;
    }
    return(count);
}
void insert(struct node *p,int pos){
    struct node *t;
    int count=count1(p);
    t=(struct node *)malloc(sizeof(struct node));
    if(pos==0){
        int x;
        printf("enter the element u want to insert\n");
        scanf("%d",&x);
        t->data=x;
        t->next=first;
        first=t;
    }
    else if(pos>0 && pos< count){
        int x;
        printf("enter the element u want to insert\n");
        scanf("%d",&x);
        t->data=x;
        p=first;
        for(int i=0;i< pos- 1;i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
    else{
        printf("enter a valid position");
    }
}
void insert1(struct node *p,int pos){
    struct node *t;
    int count=count1(p);
    t=(struct node *)malloc(sizeof(struct node));
    if(pos==0){
        int x;
        printf("enter the element u want to insert\n");
        scanf("%d",&x);
        t->data=x;
        t->next=first;
        first=t;
    }
    else if(pos>0 && pos< count){
        int x;
        printf("enter the element u want to insert\n");
        scanf("%d",&x);
        t->data=x;
        p=first;
        for(int i=0;i< pos- 1;i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
    else{
        printf("enter a valid position");
    }
}
void append(struct node *p,int x){
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;
    if(first==NULL){
        first=last=t;
    }
    else{
        last->next=t;
        last=t;
    }
}
int main()
{
    struct node *temp;
    int a[]={3,5,7,20,15};
    /*we can also insert using append funcntion
    append(first,8);
    append(first,9);
    append(first,10);*/
    /*
    making node from 0th element
    insert1(first,0);
    display(first);
    printf("\n");
    insert1(first,0);
    display(first);
    printf("\n");
    insert1(first,1);
    display(first);*/
    create(a,5);
    insert(first,3);
    display(first);
    printf("\n");
    insert(first,5);
    display(first);
    
    
}