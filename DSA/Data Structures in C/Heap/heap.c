#include<stdio.h>
void Insert(int A[],int n){
    int i=n,temp;
    temp=A[i];
    while(i>1 && temp>A[i/2]){
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}
void delete(int A[],int n){
    int i,j,x,temp,val;
    x=A[n];
    val=A[1];
    A[1]=A[n];
    i=1;j=i*2;
    A[n]=val;
    while(j<n-1){
        if(A[j+1]>A[j]){
            j=j+1;
        }
        if(A[i]<A[j]){
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i=j;
            j=2*j;
        }
        else{
            break;
        }
    }

}
int main(){
    int H[]={0,10,20,30,25,5,40,35};
    for(int i=2;i<=7;i++){
        Insert(H,i);
    }
    for(int i=1;i<=7;i++){
        printf("%d ",H[i]);    
    }
    printf("\n");
    delete(H,7);
    for(int i=1;i<=7;i++){
        printf("%d ",H[i]);    
    }
    return 0;
}