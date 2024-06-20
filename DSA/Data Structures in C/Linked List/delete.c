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
void insert1(struct node *p,int pos,int x){
    struct node *t;
    int count=count1(first);
    t=(struct node *)malloc(sizeof(struct node));
    if(pos==0){
        t->data=x;
        t->next=first;
        first=t;
    }
    else if(pos>0 && pos<= count){
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
int to_find_pos_sorted_list(struct node *p,int x){
    int count=0;
    int count1=0;
    while(p!=NULL){
        if(p->data<x){
            count++;
        }
        count1++;
        p=p->next;
    }
    if(count<count1){
        return(count);
    }
    else{
        return(count1);
    }
}// sir code
/*void SortedInsert(struct Node *p,int x)
{
struct Node *t,*q=NULL;

t=(struct Node*)malloc(sizeof(struct Node));
t->data=x;
t->next=NULL;
if(first==NULL)
first=t;
else
{
while(p && p->data<x)
{
q=p;
p=p->next;
}
if(p==first)
{
t->next=first;
first=t;
}
else
{
t->next=q->next;
q->next=t;
}
}
}*/
void del(struct node *p,int pos){
    struct node *q;
    q=first;
    int count=count1(first);
    printf("%d",count);
    if(pos == 0){
        first=first->next;
        int x=p->data;
        free(p);
        printf("deleted %d at pos %d\n",x,pos);
    }
    else if(pos>0 && pos< count){
        for(int i=0;i<=pos;i++){
            p=p->next;
        }
        for(int i=0;i<=pos-1;i++){
            q=q->next;
        }
        q->next=p->next;
        int x=p->data;
        free(p);
        printf("deleted %d at pos %d\n",x,pos);
    }
    else{
        printf("invalid pos");
    }
}
int delete(struct node *p,int index)
{
    struct node *q=NULL;
    int x=-1,i;
    if(index==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    else
    {
        for(i=0;i<index-1;i++)
        {
        q=p;
        p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
}
int main()
{
    struct node *temp;
    int a[]={3,5,7,15,20};
    create(a,5);
    int b;
    printf("enter the element to be append in the list\n");
    scanf("%d",&b);
    int position=to_find_pos_sorted_list(first,b);
    insert1(first,position,b);
    display(first);
    printf("\n");
    
    //del(first,5);
    delete(first,5);
    display(first);
    
    
}