#include <algorithm>
#include<bits/stdc++.h> 
using namespace std;
void solve()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int> x(n);
        for(int i = 0;i<n;i++)
        cin>>x[i];
        cout<<*max_element(x.begin(),x.end()) + *min_element(x.begin(),x.end())<<"\n";

    }
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}
