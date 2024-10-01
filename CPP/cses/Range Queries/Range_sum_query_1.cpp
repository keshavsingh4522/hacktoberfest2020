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
    int n,q;
    cin>>n>>q;
    vector<long long> a;
    long long s=0;
    while(n--){
        long long q1;
        cin>>q1;
        s+=q1;
        a.push_back(s);
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        if(l-2<0)
        cout<<a[r-1]<<endl;
        else
        cout<<a[r-1]-a[l-2]<<endl;
    }
    
}