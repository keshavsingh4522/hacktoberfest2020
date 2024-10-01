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
 
 
main(){
    long long n;
    cin>>n;
    long long ans=0;
    while(n!=0){
        long long m=n;
        long long max=0;
        while(m/10!=0){
            if(m%10>max){
                max=m%10;
            }
            m/=10;
        }
    if(m>max){
        max=m;
    }
    n-=max;
    ans++;
    }
    cout<<ans;
}
 