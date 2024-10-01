#include<iostream>
#include<math.h>
using namespace std;
int i=0;
int count(int A[],int n, int diff,int per,int sum)
{
	if(n==0)
	{
		return abs((sum-per)-per);
	}
	else
	{
		if(count(A,n-1,diff,per+A[n-1],sum)==diff)
		{
			i++;
		}
		if(n!=3)
		{
			return count(A,n-1,diff,per,sum);
		}
	}
}
int main()
{
	int A[]={1,1,2,3};
	int diff=1;
	int n=3;
	count(A,n,diff,0,5);
	cout<<i;
}
