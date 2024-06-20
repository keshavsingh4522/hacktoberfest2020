#include <stdio.h>
#include <stdlib.h>
struct node {
    struct node *prev;
    int data;
    struct node *next;
}*first=NULL;
void create(int a[],int n){
    struct node *t,*last;
    int i;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=first->prev=NULL;
    last=first;
    for(i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=NULL;
        t->prev=last;
        last->next=t;
        last=t;
    }
}
void display(struct node *p){
    do{
        printf("%d",p->data);
        p=p->next;
        if(p->next==NULL){
            printf("%d",p->data);
        }
    }while(p->next!=NULL);

    printf("\n");
    while(p!=first){
        if(p->next==NULL){
            printf("%d",p->data);
        }
        p=p->prev;
        printf("%d",p->data);

    }
    printf("\n");
}
int length(struct node *p){
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}
void insert(struct node *p,int index){
    struct node *t;
    int x;
    printf("\nEnter the number u want to insert at index %d :",index);
    scanf("%d",&x);
    t=(struct node *)malloc(sizeof(struct node *));
    t->data=x;
    for(int i=0;i<index-1;i++){
        p=p->next;
    }
    if(index==length(first)){
        t->data=x;
        t->prev=p;
        p->next=t;
        t->next=NULL;
    }
    else{
        t->next=p->next;
        p->next=t;
        t->prev=p;
        t->next->prev=t;
    }
}
/*void delete1(struct node *p,int pos){
    for(int i=0;i<pos-1;i++){
        p=p->next;
    }
    if(pos==length(first)){
        struct node *t=p->next;
        p->next=NULL;
        int x;
        x=t->data;
        t->prev=NULL;

    }
    int x;
    p->prev->next=NULL;
    p->prev=NULL;
    x=p->data;
    printf("\n%d element at index %d from the list is deleted",x,index);
    free(p);
}*/
void delete1(struct node *p,int pos){
    for(int i=0;i<pos-1;i++){
        p=p->next;
    }
    int x;
    if(p==first){
        first=first->next;
        p->next->prev=NULL;
        p->next=NULL;
        x=p->data;
        free(p);
    }
    else{
        p->prev->next=p->next;
        if(p->next){
            p->next->prev=p->prev;
        }
        x=p->data;
        free(p);
    }
}
void Reverse(struct node *p)
{
    struct Node *temp;
    while(p!=NULL)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL)
            first=p;
    }
}
int main(){
    int a[5]={1,2,3,4,5};
    create(a,5);
    //insert(first,5);
    //delete1(first,1);
    Reverse(first);
    display(first);
    //printf("length %d ",length(first));

}