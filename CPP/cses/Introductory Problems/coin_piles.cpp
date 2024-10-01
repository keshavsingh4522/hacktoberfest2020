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
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long a,b;
        cin>>a>>b;
        long max=a>b?a:b;
        long min=a>b?b:a;
        if((a+b)%3==0){
            if(max<=2*min){
                cout<<"YES";
            }
            else{
                cout<<"NO";
            }
        }
        else{
            cout<<"NO";
        }
        cout<<endl;
    }
}

    
    