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
void display(struct node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}
void display_recusively(struct node *p){
    if(p!=NULL){
        //to display linkedlist in reverse use this first display(p->next); then print
        printf("%d ",p->data);
        display(p->next);
    }
}
int count(struct node *p){
    int count=0;
    while(p){
        count++;
        p=p->next;
    }
    return(count);
}
int count_recusively(struct node *p){
    if(p!=NULL){
        return count_recusively(p->next)+ 1;
    }
    else{
        return 0;
    }
}
int add(struct node *p){
    int sum=0;
    while(p){
        sum=sum+p->data;
        p=p->next;
    }
    return(sum);
}
int add_recusively(struct node *p){
    if(p!=NULL){
        return add_recusively(p->next)+ p->data;
    }
    else{
        return 0;
    }
}
int main()
{
    int a[]={3,5,7,10,15};
    create(a,5);
    //showing and counting
    display(first);
    printf("\n");
    printf("%d",count(first));
    printf("\n");
    display_recusively(first);
    printf("\n");
    printf("%d",count_recusively(first));
    printf("\nsum of element\n");
    printf("%d",add(first));
    printf("\nsum of element recusively\n");
    printf("%d",add_recusively(first));
    
    return 0;
}
