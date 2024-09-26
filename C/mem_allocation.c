#include<stdio.h>
#include<stdlib.h>
int n,p;
struct space{
    int bs;
    int mu;
    int pid;
    int id;
    struct space *rlink;
    struct space *llink;
};
struct space *add(struct space *head,int x,int i){
    struct space *temp,*current;
    temp=(struct space *)malloc(sizeof(struct space));
    temp->bs=x;
    temp->mu=0;
    temp->pid=-1;
    temp->id=i;
    temp->rlink=NULL;
    temp->llink=NULL;
    current=head;
    if(head==NULL){
        head=temp;
        printf("CP");
    }
    else{
        while(current->rlink!=NULL){
            current=current->rlink;
        }
        temp->llink=current;
        current->rlink=temp;
    }
    return (head);
}
void display(struct space *head){
    int i,j;
    struct space *current=head;
    while(current!=NULL){
        printf("\n%d\t%d\t%d\t%d",current->id,current->bs,current->mu,current->pid);
        current=current->rlink;
    }
}
void best(struct space *head, int process[]){ 
    int i,j;
    int min,completed[10]={0};
    struct space *minnode=NULL,*current;
    for(i=0;i<p;i++){
        min=-1;
        current=head;
        while(current!=NULL){
            if(current->bs > process[i]&&current->mu==0){
                if(min==-1){
                    min=current->bs-process[i];
                    minnode=current;
                }
                else{
                    if(current->bs-process[i] < min){
                        min=current->bs-process[i];
                        minnode=current;
                    }
                }
            }
            current=current->rlink;
        }
        if(minnode!=NULL){
            minnode->mu=process[i];
            minnode->pid=i;
        }
    }
    display(head);
}
void main(){
    int i,x,process[20];
    struct space *head=NULL;
    printf("Enter the number of blocks : ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        printf("Enter the block size of %d: ",i);
        scanf("%d",&x);
        head = add(head,x,i);
    }
    printf("Enter the number of processes : ");
    scanf("%d",&p);
    printf("Enter the processes : ");
    for(int i=0;i<p;i++)
        scanf("%d",&process[i]);
    best(head,process);
}
