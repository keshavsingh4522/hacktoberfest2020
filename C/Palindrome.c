#include<stdio.h>
int revers(int n)
{
	int s=0,i,r;
	
	while(n>0)
	{
		r = n%10;
		s = s*10 + r;
		n = n/10;
	}
	
	return s;
}

int main()
{
	int n,ans;
	
	printf("Enter Value : ");
	scanf("%d",&n);
	
	ans = revers(n);
	
	if(ans == n)
	{
		printf("\n%d is Palindrome Number...",n);
	}
	else
	{
		printf("\n%d is Not Palindrome Number...",n);
	}
	

}
