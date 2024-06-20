#include<bits/stdc++.h>
using namespace std;
int dp[7][11]={-1};

int solve(int arr[], int sum, int n){
	for(int i=0; i<n+1; i++){
		for(int j=0; j<sum+1; j++){
			if(i==0){
				dp[i][j]=0;
				
			}
			if(j==0){
				dp[i][j]=1;
			}
		}
	}
	
	for(int i=1; i<n+1; i++){
		for(int j=1; j<sum+1; j++){
			if(arr[i-1]<=j){
				dp[i][j]= dp[i-1][j]+dp[i-1][j-arr[i-1]];
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	
	return dp[n][sum];
}





int main(){
	int arr[]={1,1,2,3};
	int diff=1;
	int n=sizeof(arr)/sizeof(arr[0]);
	int sum=0;
	for(int i=0; i<n; i++){
		sum+=arr[i];
	}
	
	int val = (sum+diff)/2;
	
	cout<<solve(arr,val,n)<<endl;
	return 0;
}