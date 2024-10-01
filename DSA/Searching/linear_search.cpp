#include <iostream>
using namespace std;

int search(int n,int arr[],int key)
{
    for(int i=0;i<n;i++)
    {
        if(key==arr[i])
        return i;
    }
    return -1;
}

int main() {
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr);
    int key=3;

    int res = search(n,arr,key);
    if(res==-1)cout<<"NOT FOUND";
    else cout<<"Found at index"<<res;
    return 0;
}
