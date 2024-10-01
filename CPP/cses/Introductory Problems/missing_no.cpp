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
    long n;
    cin>>n;
    vector<long> a;
    for(long i=0;i<n-1;i++){
        long q;
        cin>>q;
        a.push_back(q);
    }
    int t=0;
    sort(a.begin(),a.end());
    for(int i=0;i<n-1;i++){
        if(a[i]!=i+1){
            cout<<i+1;
            t++;
            break;
        }
    }
    if(t==0){
        cout<<n;
    }
}

    
    