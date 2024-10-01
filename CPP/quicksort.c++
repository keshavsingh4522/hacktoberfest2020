# include<bits/stdc++.h>
using namespace std;
void swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int  partition(int arr[],int l,int r){
    int pivot=arr[r];
    int i=l-1;
    
    for( int j=l;j<r;j++){
        if(arr[i]<pivot){
             i++;
             swap(arr,i,j);
        }
    
    }
    swap(arr,i+1,r);
    return i+1;
}
void quicksor(int arr[],int l,int r){
if(l<r){
    int pi=partition(arr,l,r);
    quicksor(arr,l,pi-1);
    quicksor(arr,pi+1,r);
}
}
int main(){
int arr[]={1,2,3,466,77,4};
quicksor(arr,0,5);
for(int i=0;i<6;i++){
    cout<<arr[i]<<" ";
}
return 0;
}
