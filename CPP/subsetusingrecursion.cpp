#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define asc(i,x,n) for(I i=x;i<n;i++)
#define dsc(i,x,n) for(I i=x;i>=n;i--)
#define W(t) int t;cin>>t;while(t--)
#define U unsigned
#define I long long int
#define S string
#define C char
#define D long double
#define A auto
#define B bool
#define pb push_back
#define V(x) vector<x>
#define mod 1000000007
V(V(int)) subsets;
void genrate(V(int) &subset,int i,V(int) &num)
 
{   if(i==num.size())
    {
        subsets.pb(subset);
        return;

    }
     
    genrate(subset,i+1,num);//if we not include ith element in our vector

    subset.pb(num[i]);//if we want to include ith element in subset
    genrate(subset,i+1,num);
    subset.pop_back();

}
int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int n;
cin>>n;
V(int) num(n);
asc(i,0,n){
    cin>>num[i];
}
V(int ) empty;
genrate(empty,0,num);
for(auto subset:subsets)
{  cout<<endl;
    for(auto ele:subset)
    {
        cout<<ele<<" ";
    }
}
return 0;
}