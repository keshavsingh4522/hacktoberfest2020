#include <bits/stdc++.h>
typedef unsigned long long int lli;

using namespace std;
void def(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);  
    #endif
}
int main()
{   //Ctrl+Alt+N to RUN
    def();
    int n;
    cin>>n;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
      int a;
      cin>>a;
      m[a]++;
    }
    int ans=0;
    for(auto i:m){
      ans+=i.second/2;
      if(i.second & 1)
        ans++;
    }

    cout<<ans<<"\n";

    return 0;       
}
