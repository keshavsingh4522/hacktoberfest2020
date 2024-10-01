#include<iostream>
using namespace std;
bool subset_sum(int A[],int sum, int n)
{
	int m[n+1][sum+1];
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			if(j==0)
			{
				m[i][j]=1;
			}
			else
			{
				m[i][j]=0;
		    }
		}
    }
	for(int i=1;i<n+1;i++)
		{
			for(int j=1;j<sum+1;j++)
			{
				if(A[i-1]<=j)
				{
					m[i][j]=(1&&m[i-1][j-A[i-1]])||(m[i-1][j]);
				}
				else if(A[i-1]>j)
				{
					m[i][j]=m[i-1][j];
				}
			}
		}
		for(int i=0;i<n+1;i++)
		{
			for(int j=0;j<sum+1;j++)
			{
				cout<<m[i][j]<<"\t";
			}
			cout<<"\n";
		}
	return m[n][sum];
}
int main()
{
	int A[]={2,3,7,8,10};
	int sum=11;
	int n=5;
	subset_sum(A,sum,n);
}
