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
bool is_sorted(struct node *p){
    int x=-320000;
    while(p!=NULL){
        if(p->data<x){
            return false;
        }
        x=p->data;
        p=p->next;
    }
    return true;
}
int main()
{
    struct node *temp;
    int a[]={3,5,15,7,20};
    create(a,5);
    bool sorted;
    sorted=is_sorted(first);
    if(sorted==true){
        printf("given list is sorted");
    }
    else{
        printf("given list is not sorted");
    }
    
    
}