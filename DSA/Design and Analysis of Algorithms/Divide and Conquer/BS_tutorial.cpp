#include<bits/stdc++.h> 
using namespace std;
int binary_search(int low,int high,int elem,vector<int> &x)
{
    if(low <= high)
    {
        int mid = low + (high-low)/2;
        if(x[mid] < elem)
        return binary_search(mid+1, high, elem, x);
        else if(x[mid] > elem)
        return binary_search(low, mid-1, elem, x);
        else
         return mid;
    }
    return -1;
}
void solve()
{
    int n ,q,temp,index;
    cin>>n;
    vector<int> x(n);
    for(int i = 0;i<n;i++)
    cin>>x[i];
    sort(x.begin(),x.end());    
    cin>>q;
    while(q--)
    {
        cin>>temp;
        index = binary_search(0,n-1,temp,x);
        cout<<index+1<<"\n";
        
    }
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}
