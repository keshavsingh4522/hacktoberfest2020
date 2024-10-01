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
 
main(){
    long n;
    cin>>n;
    long long s=1;
    for(int i=0;i<n;i++){
        s*=2;
        s%=M;
    }
    cout<<s;
}