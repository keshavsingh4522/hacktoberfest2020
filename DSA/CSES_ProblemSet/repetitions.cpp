#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

/*
You are given a DNA sequence: a string consisting of characters A, C, G, and T. 
Your task is to find the longest repetition in the sequence. This is a maximum-length substring containing only one type of character.

input:
ATTCGGGA

output:
3
*/

int32_t main()
{
  IOS;
  string s;
  cin>>s;

  int ans = 1;
  int count = 1;

  for(int i=1; i<s.length(); i++)
  {
    if(s[i]==s[i-1]) count++;
    else count = 1;

    ans = max(ans, count);
  }
  cout<<ans<<endl;
  return 0;
}

