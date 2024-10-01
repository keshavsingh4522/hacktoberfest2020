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
    int n;
    cin>>n;
    pair<int,int> p[n];
    for(int i=0;i<n;i++){
        int q,w;
        cin>>q>>w;
        p[i]=make_pair(q,w);
    }
    sort(p,p+n);
    long t=0,ans=0;
    for(int i=0;i<n;i++){
        t+=p[i].first;
        ans+=p[i].second-t;
    }
    cout<<ans;
}