#include <bits/stdc++.h>
using namespace std;
#define ll long long

//only for numbers in the range -1e3 to 1e3 : 
void counting_sort(vector<ll> &v){
    vector<ll> hash(int(1e6), 0) ;
    for(auto x : v){
        hash[int(1e3) + x]++;
    }
    v.clear();
    for(int j = 0 ; j < hash.size() ; j++){
        if(hash[j] > 0){
            for(int i = 0 ; i < hash[j] ; i++){
                v.push_back(j-int(1e3));
            }
        }
    }
}
void solve(){
    ll n ; cin >> n ;
    vector<ll> v(n);
    for(auto &x : v){
        cin >> x;
    }
    counting_sort(v);
    for(auto x : v){
        cout << x << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
}
// Time Complexity:
// Worst case time-	O(n)
// Best case time- 	O(n)
// Average case time-	O(n)

//Space complexity:
// Space-	O(n)
