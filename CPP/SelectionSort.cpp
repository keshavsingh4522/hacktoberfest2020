#include <iostream>
using namespace std;
 
void selectionsort(int A[],int N)
{
  for(int i=0;i<n-1;i++)
  {
    int small=i;
    for(int j=i+1;j<n;j++)
  
      if(A[small]>A[j])
        small=j;
    
    if(small!=i)
    {
      int temp=A[small];
      A[small]=A[j];
      A[j]=A[temp];
    }
  }
}

int main()
{
  int A[1000],int n;
  cout<<"Enter the size of Array: \n";
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>A[i];
  cout<<"the sorted array is :";
  selectionsort(A,n);
  return 0;
}
