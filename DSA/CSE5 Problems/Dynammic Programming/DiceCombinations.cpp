#include<bits/stdc++.h> 
using namespace std;
const int mod = 1000000007;
vector<int> memo(10000000,-1);
int findanswer(int sum)
{
 
    if(sum == 0 or sum == 1)
    return 1;

    else if(memo[sum] != -1)
    return memo[sum];

    int ans = 0;
    for(int i  = 1; i <= 6;i++)
    {
        if(sum - i >= 0)
        ans = (ans%mod +  (findanswer(sum - i))%mod)%mod;
    }
    memo[sum] = ans;
    return ans;

    
}
void solve()
{
   
    int n ;
    cin>>n;
    cout<<findanswer(n)<<"\n";
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
solve();
return 0;
}
