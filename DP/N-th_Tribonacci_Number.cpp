#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int tribonacci(int n) {
        int dp[n+3];
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-3]+dp[i-2]+dp[i-1];
        }
        return dp[n];
}

int main(){
	int x;
    long long ans;
    cout<<"Enter a number: ";
	cin>>x;
	ans=tribonacci(x);
    cout<<x<<"th Tribonacci number is "<<ans;
    return 0;
}