#include<bits/stdc++.h> 
using namespace std;
int binary_search(int low,int high,int elem,vector<int> x)
{
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(x[mid] < elem)
            low = mid+1;
        else if(x[mid] > elem)
        high = mid -1;
        else
         return mid;
    }
    return -1;
}
void solve()
{
    int n,elem,search;
    cout<<"Enter Number of elements: ";
    cin>>n;
    cout<<"\nEnter elements: ";
    vector<int > x(n);
    for(int i = 0;i<n;i++)
    cin>>x[i];
    cout<<"\nEnter element to be searched: ";
    cin>>search;
    sort(x.begin(),x.end());
    int ans = binary_search(0, x.size()-1,search, x);
    if(ans ==-1)
    cout<<"\nElement not found\n";
    else
     cout<<"\nElement found at index: (after sorting)"<<ans;
}
int main()
{

solve();
return 0;
}
