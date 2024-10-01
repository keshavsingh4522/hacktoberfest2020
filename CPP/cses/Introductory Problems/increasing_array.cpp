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
    int n;
    cin>>n;
    vector<long> a;
    for(int i=0;i<n;i++){
        long q;
        cin>>q;
        a.push_back(q);
    }
    long long s=0;
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]){
            s+=a[i-1]-a[i];
	    a[i]=a[i-1];
        }
    }
    cout<<s;
}

    
    