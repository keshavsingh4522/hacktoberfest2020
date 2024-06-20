#include<bits/stdc++.h> 
#define ll long long 
using namespace std;
void solve()
{
    ll t,X;
    string s;
    cin>>t;
    stack<pair<string,ll>> x;
    stack<int> count;
    while(t--)
    {
         cin>>X;
         if(X==-1)
         {
             cout<<count.top()<<" "<<x.top().first<<"\n";
             count.pop(),x.pop();
         }
         else 
         {
             cin>>s;
             if(X!=0)
             {
                 if(x.empty() || x.top().second>=X)
                 {
                       x.push(make_pair(s,X));
                       count.push(0);
                 }
                 else 
                 {
                    ll k = count.top();
                     count.pop();
                     count.push(k+1);
                 }
             }
         }
    }
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}
