#include<stdio.h>
#include<stdlib.h>

#define MALLOC(x,size,type) ( x=(type*)malloc(size*sizeof(type*)))
typedef struct{int key;}element;
element *queue=NULL;
int capacity=1;
void copy(element *start,element *end,element *newqueue){
    int i;
    element *j;
    j=start;
    for(i=0;j<end;j++,i++)
        *(newqueue+i)=*j;

}

void queuefull(int *front,int *rear){
    element *newqueue;
    newqueue=(element*)malloc(2*capacity*sizeof(*queue));
    int start=(*front+1)%capacity;
    if(start<2)
        copy(queue+start,queue+start+capacity-1,newqueue);
    else{
        copy(queue+start,queue+capacity,newqueue);
        copy(queue,queue+*rear+1,newqueue+capacity-start);

    }
    *front=2*capacity-1;
    *rear=capacity-2;
    capacity=capacity*2;
    free(queue);
    queue=newqueue;
}



void addcq(int *front,int *rear,element item){

    *rear=(*rear+1)%capacity;
    if(*front==*rear)
    {
        queuefull(front,rear);
        *rear=(*rear+1)%capacity;
    }

    queue[*rear]=item;

}
void deletecq(int *front, int rear){

    if(*front==rear)
    {
        printf("QUEUE IS EMPTY . UNDERFLOW\n");
        return;
    }

    *front=(*front+1)%capacity;
     printf("Deleted element is %d",queue[*front].key);

}
void display(int front,int rear){

    if(front==rear)
    {
        printf("Empty Queue\n");
        return;
    }
    printf("\nThe current circular queue is\n");
    for(int i=(front+1)%capacity;i!=(rear+1)%capacity;i=(i+1)%capacity)
        printf("%d\t",queue[i].key);
}



int main(){
    MALLOC(queue,sizeof(element),element);
    int f=0,r=0,s;
    char c='y';
    int t;
    element item;
    while(c=='y'||c=='Y')
    {
        printf(" Menu:\n1.Insert\n2.Delete\n3.Display \nEnter choice");
        scanf("%d",&s);
        switch(s)
        {
            case 1:
                    printf("\n Enter element to be inserted ");
                    scanf("%d",&item.key);
                    addcq(&f,&r,item);
                    break;
            case 2: deletecq(&f,r);
                    break;
            case 3: display(f,r);
        }
    printf("\nWant to continue y/n ");
    scanf(" %c",&c);
    }

}

