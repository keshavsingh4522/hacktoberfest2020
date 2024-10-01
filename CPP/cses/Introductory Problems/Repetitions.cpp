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
    string ch;
    cin>>ch;
    vector<int> a;
    int x=1;
    int m=0;
    for(int i=1;i<ch.size();i++){
        if(ch[i]==ch[i-1]){
            x++;
        }
        else{
            if(x>m){
            a.push_back(x);
            m=x;
            }
            x=1;
        }
    }
    if(x>m)
    a.push_back(x);
    cout<<a[a.size()-1];
}