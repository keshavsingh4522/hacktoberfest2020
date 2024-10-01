#include<iostream>
using namespace std;
int main()
{
    int arr[10],i,j,n,temp;
    cout<<"Enter The Maximum Number of Element You Want To Enter";
    cin>>n;
    cout<<"Enter Array Elements";
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for(i=1;i<=n-1;i++)
    {
        for(j=1;j<=n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout<<"Third Largest Element of Array After Sorting is "<<arr[n-3];
}
