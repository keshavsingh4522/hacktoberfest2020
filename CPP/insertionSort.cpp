#include <bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int n){
    for(int i=0;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
int main()
{
    int a[]={3,2,5,6,4};
    int m=sizeof(a)/sizeof(a[0]);
    insertionSort(a, m);
    for(int i=0;i<m;i++){
        cout<<a[i]<<" ";
    }
}
