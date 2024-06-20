#include<bits/stdc++.h> 
using namespace std;
long long int merge(vector<long long int> &x,long long int low,long long int mid,long long int high)
{
    vector<long long int> y;
    long long int ans = 0;
    long long int i = low, j = mid+1;
    while(i <= mid and j<= high)
    {
        if(x[i] <= x[j])
            y.push_back(x[i++]);
        else if(x[j]< x[i])
        y.push_back(x[j++]),ans += mid - i + 1;
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

 long long int counter = 0;
 for(long long int i = low;i<=high;i++)
 x[i] = y[counter++];

    return ans;
}
long long int mergesort(vector<long long int> &x, long long int low,long long int high)
{
    
    if(low < high)
    {
        long long int mid = low + (high-low)/2;
        long long int a,b,c;
        a = mergesort(x,low,mid);
        b = mergesort(x, mid+1,high);
        c = merge(x,low,mid,high);
        return a+b+c;

    }
    return 0;
    
    
  

}
void solve()
{
    long long int n,ans = 0;
    cin>>n;
    vector<long long int> x(n);
    for(long long int i = 0;i<n;i++)
    cin>>x[i];
    ans = mergesort(x,0,n-1);
    cout<<ans;
    // for(long long int elem : x)
    // cout<<elem<<" ";
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}
