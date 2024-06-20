#include<stdio.h>
#include "Queue.h"
#ifndef Stack_h
struct Stack{
    int size;
    int top;
    int **s;
};
void create(struct stack *p){
    printf("enter the size\n");
    scanf("%d",&p->size);
    p->top=-1;
    p->s=(int *)malloc(p->size*sizeof(int));
}
void display(struct stack *p){
    int i;
    for(i=p.top;i>=0;i--){
        printf("%d",p.s[i]);
    }
    printf("\n");
}
void push(struct stack *p,int x){
    if(p->top==p->size-1){
        printf("stack overflow\n");
    }
    else{
        p->top++;
        p->s[p->top]=x;
    }
}
int pop(struct stack *p){
    int x=-1;
    if(p->top==-1){
        printf("stack underflow");
    }
    else{
        x=p->s[p->top];
        p->top--;
    }
    return x;
}
int peek(struct stack p,int index){
    int x=-1;
    if(p.top-index+1<0){
        printf("invalid index");
    }
    x=p.s[p.top-index+1];
    return x;
}
int isEmpty(struct stack st)
{
    if(st.top==-1)
        return 1;
    return 0;
}
int isFull(struct stack st)
{
    return st.top==st.size-1;
}
int stackTop(struct stack st)
{
    if(!isEmpty(st))
        return st.s[st.top];
    return -1;
}
#endif