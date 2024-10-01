#include<bits/stdc++.h>

using namespace std;



int knapsack(int val[],int wt[],int w,int n){
    
    if(n==0||w==0){
        return 0;
    }
    if(w>=wt[n-1]){
        int p1=val[n-1]+knapsack(val,wt,w-wt[n-1],n-1);//when the item is accepted
        int p2=knapsack(val,wt,w,n-1);//when the item is not accepted
        return max(p1,p2);
    }
    else{
        int p2=knapsack(val,wt,w,n-1);//when the item is not selected
        return p2;
    }
}

int main(){
    int n,W;
    int val[n],wt[n];
    cin>>n,W;
    for(int i=0;i<n;i++){
        cin>>val[i]>>wt[i];
    }
    cout<<knapsack(val,wt,W,n);

}