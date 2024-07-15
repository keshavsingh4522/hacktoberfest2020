/* through this question  I am going explain segement tree*/

/*Minimum In SubArray
Send Feedback
You are given a sequence A[1], A[2], ..., A[N] of N numbers ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are Q queries, and each query is defined in either of the following two ways:
Query on range:
You are given two numbers i and j; the answer to each query is the minimum number between the range (i, j) (including both i and j). Note that in this query, i and j lies in the range: [1, N].
Update query:
You are given two numbers i and B; update A[i] to B. Note that in this query, i lies in the range: [1, N].
Input Format:
The first line of input contains two integers: N and Q, representing the length of the sequence and the number of queries. 
The second line of input contains N space-separated integers, A[i].  
Next, Q lines contain the queries. Each line contains one character, followed by two space-separated integers. For the query on range, the character will be q and for the update query, the character will be u. 
Constraints:
1 ≤ i ≤ N
0 ≤ B ≤ 10^8
1 ≤ i <= j ≤ N
Output Format:
For each query on range, print the minimum number between the range, in a new line.
Sample Input 1:
4 3
5 2 4 3
q 1 3
u 1 1
q 3 4
Sample Output 1:
2
3*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void build_tree(ll arr[],int s,int e,int idx,ll *dp)
{
    if(s==e)
    {
        dp[idx]=arr[s];
        return ;
    }
    
    int mid=(s+e)/2;
    build_tree(arr, s, mid, 2*idx, dp);
     build_tree(arr, mid+1, e, 2*idx+1, dp);
    
    dp[idx]=min(dp[2*idx],dp[2*idx+1]);
    
    
}

ll query(ll arr[],int s,int e,int idx,ll *dp,int l,int r)
{
    if(s>r ||e<l)
    {
        return INT_MAX;
    }
    
    else if(s>=l && e<=r)
    {
        return dp[idx];
    }
    int mid=(s+e)/2;
    
    return min(query( arr, s, mid,2*idx, dp,l, r),query( arr, mid+1,e ,2*idx+1, dp,l, r));
    
}


void update(ll arr[],int s,int e,int idx,ll *dp,int index,ll val)
{
    if(s==e)
    {
        dp[idx]=val;
        arr[index]=val;
        return ;
    }
    
    int mid=(s+e)/2;
    if(index <=mid)
    {
        update( arr, s, mid, 2*idx, dp, index, val);
    }
    
    else{
        update( arr, mid+1, e, 2*idx+1, dp, index, val);
    }

    dp[idx]=min(dp[idx*2],dp[idx*2+1]);
}
int main()
{
int n,q;
    cin>>n>>q;
    ll arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ll *dp=new ll[4*n];
    
    build_tree(arr,0,n-1,1,dp);
    for(int i=0;i<q;i++)
    {
        char c;int id,val;
        cin>>c;
        cin.ignore();
        cin>>id>>val;
        if(c=='u')
        {
            
            update(arr,0,n-1,1,dp,id-1,val);
            
        }
        
        else{
            cout<<query(arr, 0, n-1,1, dp,id-1, val-1)<<endl;
        }
    }
    
  
}