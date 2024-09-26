#include<iostream>
using namespace std;

void reverse_by(int A[],int i,int j)
{
    while(i<=j)
    {
      int temp=A[i];
      A[i]=A[j];
      A[j]=temp;
      i++;
      j--;
    }
}

void rotate_by(int A[],int n,int k)
{
    reverse_by(A,0,n-k-1);
    reverse_by(A,n-k,n-1);
    reverse_by(A,0,n-1);    
}

int main()
{
    int A[]={1,2,3,4,5,6,7};
    cout<<"Enter the Times that you wants to rotate : ";
    int k;
    cin>>k;
    int n=sizeof(A)/sizeof(A[0]);
    rotate_by(A,n,k);

    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
}
