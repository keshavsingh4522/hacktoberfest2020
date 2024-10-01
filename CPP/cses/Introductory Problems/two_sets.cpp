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
    if(n==1){
        cout<<"NO";
        exit(0);
    }
    vector<int> a;
    vector<int> b;
    a.push_back(n);
    long a1=n,b1=0;
    for(int i=n-1;i>=1;i-=4){
        b.push_back(i);
        b.push_back(i-1);
        b1+=i;
        b1+=i-1;
    }
    for(int i=n-3;i>=1;i-=4){
        a.push_back(i);
        a.push_back(i-1);
        a1+=i;
        a1+=i-1;
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    if(b[b.size()-1]==0){
        b.pop_back();
    }
    if(a[a.size()-1]==0){
        a.pop_back();
    }
    if(a1==b1){
        cout<<"YES"<<endl<<a.size()<<endl;
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl<<b.size()<<endl;
    for(int i=0;i<b.size();i++){
        cout<<b[i]<<" ";
    }
    }
    else{
        cout<<"NO";
    }
}