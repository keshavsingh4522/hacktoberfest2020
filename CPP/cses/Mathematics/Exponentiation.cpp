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
 
 
long long M=pow(10,9)+7;
 
long long p(long long x,long long y){
long long z=1;
long long h=x;
while(y){
if(y%2){
z=z*x;
z=z%M;
y--;
}
else{
x=x*x;
x%=M;
y=y/2;
//z=z*x;
}
}
return z%M;
}
 
main(){
int t;
cin>>t;
while(t--){
long long a,b;
cin>>a>>b;
cout<<p(a,b)<<endl;
}
}