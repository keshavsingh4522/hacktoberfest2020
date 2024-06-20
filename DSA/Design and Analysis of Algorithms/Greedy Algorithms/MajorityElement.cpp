#include<bits/stdc++.h> 
using namespace std;
void solve()
{
    int n ,ans,freq = 0;
    cin>>n;
    vector<int>x(n);
    for(int i = 0;i<n;i++)
    cin>>x[i];
    map<int,int> data;
    for(int elem : x)
    data[elem]++;

    for(auto elem : data)
    {
        if(elem.second > freq)
        freq = elem.second,ans = elem.first;
    }

    cout<<ans;

}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}

