#include<bits/stdc++.h> 
using namespace std;
int partition(vector<int> &x,int low,int high)
{
     int pivot = x[low],i=low+1,j = high;
     
    do{ while(x[i]<=pivot)
     i++;

     while(x[j]>pivot)
     j--;

     if(i<j)
     swap(x[i],x[j]);}while(i<j);

     swap(x[low],x[j]);
     return j;


}
void QuickSort(vector<int> &x ,int low,int high)
{
    if(low<high)
    {
        int pI = partition(x , low, high);
        QuickSort(x,low,pI-1);
        QuickSort(x,pI+1,high);
    }
}
void solve()
{
    int n;
    cout<<"Enter no. of elements in array: ";
    cin>>n;
    vector<int> x(n);
    cout<<"Enter elements of array: ";
    for(int i = 0;i<n;i++)
    {
        cin>>x[i];
    }
QuickSort(x,0,n-1);

    cout<<"Sorted Array is: ";
    for(int elem:x)
    cout<<elem<<" ";

}
int main()
{

solve();
return 0;
}