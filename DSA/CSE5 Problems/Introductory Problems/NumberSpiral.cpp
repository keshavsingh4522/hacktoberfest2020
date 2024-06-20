#include<bits/stdc++.h> 
#define ll long long 
using namespace std;
void solve()
{
    ll t, y, x;
    cin>>t;
    while(t--)
    {
        cin>>y>>x;
        if( x> y)
        {
            if(x%2 == 1)
            cout<<x*x - y + 1<<"\n";
            else{
                x--;
                cout<<x*x + y <<"\n";
            }
        }
        else{
            if(y%2 == 0)
            cout<<y*y - x + 1<<"\n";
            else{
                y--;
                cout<<y*y + x<<"\n";
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
