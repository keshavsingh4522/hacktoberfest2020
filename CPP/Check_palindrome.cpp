#include<bits/stdc++.h>
#define lli long long int
#define floop(a,b,c) for(lli a = b; a < c; a++)
using namespace std;
int main(){
  string s;
  cin >> s;
  lli count = 0;
  floop(i,0,s.length()/2){
    if(s[i] == s[n-1-i]) count++;
  }
  if(count == s.length()/2) cout << "YES";
  else cout << "NO";
  return 0;
}
