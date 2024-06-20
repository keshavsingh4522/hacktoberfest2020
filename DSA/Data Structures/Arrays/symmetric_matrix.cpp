#include<iostream>
using namespace std;
int main()
{
    int n,x,k=0;
    cout<<"Enter degree of matrix\n";
    cin>>n;
    int a[n*(n+1)/2];
    cout<<"Enter the elements\n";
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {  cin>>x;
        if(i>=j)
        a[k++]=x;

    }
    cout<<"Required Symmetric Matrx\n";
    for(int i=0;i<n;i++)
    { 
        for(int j=0;j<n;j++)
            {
              if(i>=j) 
              cout<<a[i*(i+1)/2 +j]<<" ";
              else
              cout<<a[j*(j+1)/2+i]<<" ";
            }
        cout<<endl;
    }
    
    }