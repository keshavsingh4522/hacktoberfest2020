#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int arr[]={3,5,-9,1,3,-2,3,4,7,2,-9,6,3,1,-5,4},k=0,n=sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<n;i++){
        arr[i]=max(arr[i],arr[i]+arr[i-1]);
        k=max(arr[i],k);
    }
    printf("Maximum value for current array is:: %d\n",k);
}
