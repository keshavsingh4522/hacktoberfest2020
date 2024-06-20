#include<bits/stdc++.h> 
using namespace std;
void solve()
{
    string s; 
    cin>>s;
    int ans = 0,temp = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == s[i+1])
        temp ++ ;
        else
         {
             ans = max(ans,temp);
            temp = 0;
         }

    }
    cout<<ans + 1;
    
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}
