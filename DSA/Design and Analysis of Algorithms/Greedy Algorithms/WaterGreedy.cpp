#include<bits/stdc++.h> 
using namespace std;
void solve()
{
    int t,n,cap,bottles;
    cin>>t;
    while(t--)
    {
        bottles = 0;
        cin>>n>>cap;
        vector<int>x(n);
        for(int i = 0;i<n;i++)
        cin>>x[i];
        sort(x.begin(),x.end());
        for(int elem : x)
        {
            if(cap - elem >= 0)
            bottles ++ , cap = cap - elem;
        }
        cout<<bottles<<"\n";
    }
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}
