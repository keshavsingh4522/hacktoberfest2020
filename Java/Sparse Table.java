/*Sparse Table is a data structure, that allows answering range queries.
It can answer most range queries in O(logn),but its true power is answering range minimum queries (or equivalent range maximum queries).
For those queries it can compute the answer in O(1) time. */


import java.util.*;

class sparseTable{

	int n;
	long[][]dp;
	int log2[];
	int P;
	
    /* Function to build table
     */

	void buildTable(long[] arr)
	{
		n=arr.length;
		P=(int)Math.floor(Math.log(n)/Math.log(2));
		
		log2=new int[n+1];
		log2[0]=log2[1]=0;
		for(int i=2;i<=n;i++)
		{
			log2[i]=log2[i/2]+1;
		}
		dp=new long[P+1][n];
		for(int i=0;i<n;i++)
		{
			dp[0][i]=arr[i];
		}
		
		for(int p=1;p<=P;p++)
		{
			for(int i=0;i+(1<<p)<=n;i++)
			{
				long left=dp[p-1][i];
				long right=dp[p-1][i+(1<<(p-1))];
				dp[p][i]=Math.max(left, right);
			}
		}
	}
	
	// function to query max value in a range in O(1) time complexity
	long maxQuery(int l,int r)
	{
		int len=r-l+1;
		int p=(int)Math.floor(log2[len]);
		long left=dp[p][l];
		long right=dp[p][r-(1<<p)+1];
		return Math.max(left, right);
	}
}
