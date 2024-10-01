#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int a[100], int n){
    int value,hole;
  for(int i=0;i<n;i++){
      value=a[i];
      hole = i;
      while(hole>0 && a[hole-1]>value){
          a[hole]=a[hole-1];
          hole--;
      }
      a[hole]=value;
  }
}

int main(){

  int x;
  printf("\nEnter size of array: ");
  scanf("%d",&x);
  int arr[x];
  printf("\nEnter elements of array: ");
  for(int i=0;i<x;i++){
    scanf("%d",&arr[i]);
  }
  InsertionSort(arr,x);
  printf("\nSorted array: ");
  
  
  for(int i=0;i<x;i++){
    printf("%d ",arr[i]);
  }


  return 0;
}


