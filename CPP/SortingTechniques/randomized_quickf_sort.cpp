#include <bits/stdc++.h>
using namespace std;
 
//if we apply quick sort on array of random elements then it takes time O(nlogn)
//if we apply quick sort on already sorted array then it takes O(n*2), in this case
//first we shuffle the elements of array randomly and then apply quick sort
//this is also knows as Randomised Quick Sort.

void shuffleRandomly(int *a, int s, int e)
{
    srand(time(NULL));
    int i,j,temp;
    for(j=e; j>0 ; j--)
    {
        i = rand()%(j+1);
        swap(a[i], a[j]);
    }
}

int partition(int *a, int s, int e)
{
  //it will return the index of pivot element

  int i  = s-1;
  int j = s;
  //consider pivot element to be last one
  int pivot = a[e];

  for( ;j<e; j++)
  {
      if(a[j]<=pivot)
      {
          i++; //extending the region 1 which contains numbers smaller than the pivot element
          swap(a[i], a[j]);
      }
  }

  swap(a[i+1], a[e]);
  return i+1;
}

void quickSort(int *a, int s, int e) //take O(nlogn) in average case
{
    //it will place the pivot element to its sorted place

    if(s>=e)
    return;

    int pivot = partition(a,s,e);

    //the we have to sort two arrays i.e. array left to the pivot and array right to the pivot

    quickSort(a,s,pivot-1);
    quickSort(a,pivot+1,e);
    
    
}


int main()
{
 
  int a[]={8,15,20,22,25,26,30,32,36,40};
  int s = 0;
  //initially consider the pivot element to be the last one
  int e = sizeof(a)/sizeof(int)-1;
  shuffleRandomly(a,s,e);
  cout<<"Randomly Shuffled Array: ";
  for(int i=0 ; i<=e;i++)
  {
      cout<<a[i]<<" ";
  }
  cout<<endl;
  quickSort(a,s,e);
   cout<<"Sorted Array: ";
  for(int i = s; i<=e ; i++)
  {
      cout<<a[i]<<" ";
  }
  return 0;
}

