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
void mergesort(vector<int> &x, int low,int high)
{
    
    if(low < high)
    {
        int mid = low + (high-low)/2;
        
        mergesort(x,low,mid);
        mergesort(x, mid+1,high);
        merge(x,low,mid,high);

    }
    
  

}
void solve()
{
    int n;
    cout<<"Enter the number of elements in array\n";
    cin>>n;
    vector<int> x(n);
    cout<<"Enter elements of array:\n";
    for(int i = 0;i<n;i++)
    cin>>x[i];
    mergesort(x,0,x.size()-1);
    cout<<"Sorted array is: \n";
    for(int elem : x)
    cout<<elem<<" ";
    
}
int main()
{


solve();
return 0;
}
