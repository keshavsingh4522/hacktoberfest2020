//merge sort algorithm
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void merge(int a[],int l,int r,int mid)
{
    int n1=mid-l+1;
    int n2=r-mid;
    int a1[n1],a2[n2];
    for(int i=0;i<n1;i++)
    a1[i]=a[l+i];
    for(int i=0;i<n2;i++)
    a2[i]=a[mid+1+i];
    int k=l,i=0,j=0;
    while(i<n1 && j<n2)
    {
        if(a1[i]<a2[j])
        {
            a[k]=a1[i];
            i++;
            k++;
        }
        else
        {
            a[k]=a2[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        a[k]=a1[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=a2[j];
        j++;
        k++;
    }
}
void mergesort(int a[],int l,int h)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,h);
        merge(a,l,h,mid);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}

/*
Input:
6
98 100 2 1 45 60
Output:
1 2 45 60 98 100

Complexity of the program: O(nlogn)
*/
