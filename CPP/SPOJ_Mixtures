#include<iostream>
#include<climits>
using namespace std;

int a[1000];
int dp[1000][1000];

int sum(int s, int e){
    int ans =0;
    for(int i=s; i<=e; i++){
        ans += a[i];
        ans %= 100;
    }
    return ans;
}

int solveMixture(int i, int j){
    //base case
    if(i>=j){
        return 0;
    }

    //lookup
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    dp[i][j] = INT_MAX;
    for(int k=i; k<=j; k++){
        dp[i][j] = min(dp[i][j], solveMixture(i,k) + solveMixture(k+1,j) + sum(i,k)*sum(k+1,j));
    }

    return dp[i][j];
}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dp[i][j] = -1;
            }
        }

        cout<<solveMixture(0,n-1)<<endl;
        
    }

    //Test cases and outputs
    /*  2
        2
        18 19
        342
        3
        40 60 20
        2400     */  

    return 0;
}
