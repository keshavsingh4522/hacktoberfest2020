#include<bits/stdc++.h>
using namespace std;
//total subsets=2^n. including empty subset
void solve(vector<int>a,vector<int>&v,int i,int n)
{
    if(i==n)
    {
        for(auto x:v)
        {
            cout<<x<<" ";
        }
        cout<<endl;
        return ;
    }
    v.push_back(a[i]);
    solve(a,v,i+1,n);
    v.pop_back();
    solve(a,v,i+1,n);
    return;
}
int main()
{
    vector<int>a={1,2,3};
    vector<int>v;
    int n=a.size();
    solve(a,v,0,n);
}
