#include <stdio.h>
#include <stdlib.h>
int maxElement(int arr[], int n)
{
    int i;
    int max = arr[0];
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
 
    return max;
}
void CountingSort(int a[],int n){
    int k = maxElement(a,n);
    int count[k];
    int b[n-1];
    for(int i=0;i<(k+1);i++){
        count[i]=0;
    }
    for(int j=0;j<n;j++){
        count[a[j]]++;

    }
    for(int i=1;i<=k;i++){
        count[i] = count[i] + count[i-1];
    }

    for(int i=n;i>=0;i--){
        count[a[i]]--;
        b[count[a[i]]] = a[i]; 
    }
    for(int j=0;j<n;j++){
        a[j] = b[j];
    }
}
void printArray(int a[],int n){
    printf("\nPrinting the Array\n");
    for(int i = 0;i<n;i++){
        printf("%d->",a[i]);
    }
}
int main(){
    int arr[] ={1,4,1,2,7,5,2};
    int n = sizeof(arr)/sizeof(arr[0]);
   
    printArray(arr,n);
    CountingSort(arr,n);
    printf("\nAfter applying Counting Sort\n");
    printArray(arr,n);
                   
                    
                  
    return 0;
}
