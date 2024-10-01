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
    while(n!=1){
        cout<<n<<" ";
        if(n%2==0){
            n/=2;
        }
        else{
            n=n*3+1;
        }
    }
    cout<<n;
}

    
    