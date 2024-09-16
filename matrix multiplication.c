//matrix multiplication //
#include<stdio.h>
main()
{
	int a1,a2,a3;
	printf ("enter a,b,c(m[a][b]&m[b][c]):\n");
	scanf("%d%d%d",&a1,&a2,&a3);
	
	int m1[a1][a2],m2[a2][a3],c[a1][a3];
		printf ("enter values of m[%d][%d]\n",a1,a2);
	for(int i=1;i<=a1;i++)
	{
		for(int j=1;j<=a2;j++)
		scanf("%d",&m1[i][j]);
	}
		printf ("\n enter values  of m[%d][%d]\n",a2,a3);
			for(int i=1;i<=a2;i++)
	{
		for(int j=1;j<=a3;j++)
		scanf("%d",&m2[i][j]);
	}
	printf("MULTIPLICATION OF MATRIX :\n");
		for(int i=1;i<=a1;i++)
	{ 
		for(int j=1;j<=a3;j++)
		{   int x=0;
		    for(int k=1;k<=a2;k++)
		    x=x+(m1[i][k]*m2[k][j]);
			c[i][j]=x;
		}
	}
		for(int i=1;i<=a1;i++)
	{
		for(int j=1;j<=a3;j++)
		printf("%d\t",c[i][j]);
		printf("\n");
	}   
}
