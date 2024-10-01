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
    if(n==1){
    cout<<1;
    }
    else if(n<=3){
        cout<<"NO SOLUTION";
    }
    else if(n%2==0){
        int m=n-1;
        while(m!=1){
            cout<<m<<" ";
            m-=2;
        }
        cout<<1<<" ";
        while(n!=2){
            cout<<n<<" ";
            n-=2;
        }
        cout<<2;
    }
    else{
        int m=n-1;
        while(n!=1){
            cout<<n<<" ";
            n-=2;
        }
        cout<<1<<" ";
        while(m!=0){
            cout<<m<<" ";
            m-=2;
        }
    }
}

    
    