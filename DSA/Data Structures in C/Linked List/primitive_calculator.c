#include <iostream>

using namespace std;
struct node{
    int data;
    struct node *next;
}*first=NULL,*last;
void append(struct node *p,int x){
    struct node *t;
    t=new node;
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
void display( struct node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}
int main()
{
    int input_number;
    cin>>input_number;
    int count=0;
    int x=input_number;
    while(x>=1){
        
        if(x%3==0){
            append(first,x);
            x=x/3;
            count++;
            if((x-1)%3==0){
                x=x-1;
                append(first,x);
                count++;
            }
            else{
                
            }
        }
        else if(x%2==0){
            append(first,x);
            x=x/2;
            count++;
            
        }
        else if(x%1==0){
            if(x==1){
                append(first,x);
                x=x-1;
            }
            else{
                append(first,x);
                x=x-1;
                count++;
            }
            
        }
        else{
        }
    }

    cout<<count<<endl;
    display(first);
}
