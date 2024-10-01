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
    long long t;
    cin>>t;
    while(t--){
        long long y,x;
        cin>>y>>x;
        long long m=y>x?y:x;
        if(m%2==0){
            if(y==m){
                cout<<m*m-x+1;
            }
            else{
                cout<<m*m-(m-y)-(m-1);
            }
        }
        else{
            if(x==m){
                cout<<m*m-y+1;
            }
            else{
                cout<<m*m-(m-x)-(m-1);
            }
        }
        cout<<endl;
    }
}