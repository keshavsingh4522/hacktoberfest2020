#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long int ll;
int main(){
    ll t;cin>>t;
    while(t--){
        ll n,i,s=0;
        unordered_map<ll,int> m;
        cin>>n;
        ll a[n];
        for(i=1;i<=n;i++){
            cin>>a[i];
            m[a[i]]=0;
        }
        for(i=1;i<=n;i++){
            m[a[i]]++;
        }
        for(auto x:m){
            if(x.second>1){
                ll c = (n-x.second);
                c=c*(x.second);
                s=s+c;
            }else{
                s=s+n-1;
            }
        }
        cout<<s<<"\n";
    }
    return 0;
}