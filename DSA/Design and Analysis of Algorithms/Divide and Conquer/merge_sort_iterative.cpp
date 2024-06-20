#include<bits/stdc++.h> 
using namespace std;
void merge(vector<int> &x,int low,int mid,int high)
{
  
    vector<int> y;
    int i = low, j = mid+1;
    while(i <= mid and j<= high)
    {
        if(x[i] < x[j])
            y.push_back(x[i++]);
        else if(x[j]< x[i])
        y.push_back(x[j++]);
        else
        {
            y.push_back(x[i++]);
            y.push_back(x[j++]);
        }
    }

    while(i <= mid)
    y.push_back(x[i++]);

    while(j <= high)
    y.push_back(x[j++]);

 int counter = 0;
 for(int i = low;i<=high;i++)
 x[i] = y[counter++];


}
void mergesort(vector<int> &x)
{
    
    int curr_size,i;
    for(curr_size = 1;curr_size <x.size();curr_size = 2*curr_size)
    {
        
        for(i = 0 ;i<x.size();i+=2*curr_size)
        {
            int mid = min(i + curr_size-1,int(x.size()-1));
            int high = min(i + 2*curr_size-1,int(x.size()-1));
            merge(x,i,mid,high);
           

        }
        
    }
}
void solve()
{
    int n;
    cout<<"Enter the number of elements in array\n";
    cin>>n;
    vector<int> x(n);
    cout<<"Enter the elements of the array";
    for(int i = 0;i<n;i++)
    cin>>x[i];
    mergesort(x);
    for(int elem : x)
    cout<<elem<<" ";
    
}
int main()
{


solve();
return 0;
}
