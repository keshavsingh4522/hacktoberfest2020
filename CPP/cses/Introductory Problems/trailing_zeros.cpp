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
    long long s=0;
    long long x=5;
    while(n/x!=0){
        s+=n/x;
        x*=5;
    }
    cout<<s;
}

    
    