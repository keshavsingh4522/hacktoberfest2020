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
    long long s=0;
    vector<long> a;
    for(int i=0;i<n;i++){
        long q;
        cin>>q;
        s+=q;
        a.push_back(q);
    }
    sort(a.begin(),a.end());
    long long d=a[n/2];
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=abs(d-a[i]);
    }
    cout<<sum;
}