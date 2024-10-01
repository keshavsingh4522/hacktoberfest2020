#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
}*first=NULL; //creating a global pointer

void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
       t=(struct Node *)malloc(sizeof(struct Node));
       t->data=A[i];
       t->next=NULL;
       last->next=t; 
       last=t;
    }
    
}

void display(struct Node*p)
{
  while(p!=NULL)
  {
      printf("%d",p->data);
      p=p->next;
  }
}
void RDisplay(struct Node *p)
{
  if(p!=NULL)
  {
      //printf("%d", p->data," ");
      RDisplay(p->next);
      printf("%d", p->data," ");
  }
}

int count(struct Node *p)
{
    int l=0;
    while(p)
    {
        l++;
        p=p->next;
    }
    return l;
}

int Rcount(struct Node *p)
{
    if (p!=NULL)
    {
        return Rcount(p->next)+1;
    }
    else 
      return 0;
}
int sum(struct Node *p)
{
    int s=0;
    while(p!=NULL)
    {
        s+=p->data;
        p=p->next;
    }
    return s;
}
int Rsum( struct Node *p)
{
    if(p==NULL)
    {
        return 0;
    }
    else 
     return Rsum(p->next)+p->data;
}
int Max(struct Node *p){
    int max=INT32_MIN;//built in constant
    while(p)
    {
        if(p->data>max)
        {
            max=p->data;
        }
        p=p->next;
    }
    return max;
}
int Rmax(struct Node *p)
{
    int x=0;
    if(p==0)
        return INT32_MIN;
    x=Rmax(p->next);
    if(x>p->data)
      return x;
    else return p->data;      
}
int main()
{
    int A[]={3,5,7,10,15,34,56,78};
    create(A,8);
    display(first);
    RDisplay(first);
    printf("Length is %d", Rcount(first));
    cout<<"Sum is "<<Rsum(first);
    cout<<Rmax(first);
    return 0;
}
