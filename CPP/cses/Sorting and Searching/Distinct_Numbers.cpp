#include<iostream>
#include<vector>
#include <stdio.h>
#include<bits/stdc++.h>
#include<algorithm>
#include<cstring>
#include<set>
#include<string>
#include<math.h>
#include <iterator> 
 
using namespace std;
 
typedef long long ll;
 
long long M=pow(10,9)+7;
 
 
int main(){
int t;
cin>>t;
set<long> s;
for(int i=0;i<t;i++){
long q;
cin>>q;
s.insert(q);
}
cout<<s.size();
return 0;
}