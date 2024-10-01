#include<iostream>
#include<cassert>
#include "heap.h"
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int arr[] = { 7, 4, 6, 3, 9, 1 };
    int n = sizeof(arr)/sizeof(int);
    int k = 2;

    MinHeap M(arr,k);

    for(int i=k;i<n;i++){
        if(arr[i] > M.top()){
            M[0] = arr[i];
            M.heapify(0);
        }
    }

    cout<<"kth largest element: "<<M.top()<<endl;
    return 0;
}
