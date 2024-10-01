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
    long long n,x;
    cin>>n>>x;
    vector<long long> a;
    vector<long long> b;
    long long s=0;
    for(int i=0;i<n;i++){
        long long q;
        cin>>q;
        a.push_back(q);
        b.push_back(q);
    }
    int i=0,j=n-1,t=0;
    int a1=0,a2=0;
    sort(a.begin(),a.end());
    while(j>i){
        if(a[i]+a[j]>x){
            j--;
        }
        else if(a[i]+a[j]<x){
            i++;
        }
        else{
            a1=a[i];
            a2=a[j];
            t++;
            break;
        }
    }
    vector<long long> a3;
    if(t==0){
        cout<<"IMPOSSIBLE";
    }
    else{
        for(int i=0;i<a.size();i++){
            if(a1==b[i]||a2==b[i]){
                a3.push_back(i+1);
            }
            if(a3.size()==2){
                break;
            }
        }
        cout<<a3[0]<<" "<<a3[1];
    }
}

    
    