#include <stdio.h>
int partition(int x[],int lb,int ub){
    int up,down,pivot,temp;
    pivot=x[lb];
    up=ub;
    down=lb;
    while(down<up)
    {
    while(x[down]<=pivot  && down<ub){
        down++;
    }
    while(x[up]>pivot){
        up--;
    }
    if(down<up)
    {
        temp=x[down];
        x[down]=x[up];
        x[up]=temp;
    }
    }
    x[lb]=x[up];
    x[up]=pivot;
    return up;
    }

void  quicksort(int arr[], int lb, int ub){
    int j;
    if (lb>=ub)
        return;

    j = partition(arr,lb,ub);
    quicksort(arr,lb,j-1);
    quicksort(arr,j+1,ub);

}


int main() 
{

    int n,i,v,arr[100];
    printf("enter the total no of elements: ");
    scanf("%d",&n);
    printf("enter the values: \n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

   quicksort(arr,0,n-1);

   printf("Order of Sorted elements  using quick sort:\n ");

    for(i=0;i<n;i++)
      printf(" %d",arr[i]);

    return 0;
}
