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
    long long n;
    cin>>n;
    long long t=3,j=3;
    for(long long i=1;i<=n;i++){
        if(i==3)
        cout<<((i*i*(i*i-1))/2)-(8);
        else if(i>3){
        cout<<((i*i*(i*i-1))/2)-8*t;
            t+=j;
            j++;
        }
        else
        cout<<((i*i*(i*i-1))/2);
        cout<<endl;
    }
}