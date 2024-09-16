#include<iostream>
#include<cstring>

using namespace std;

char b[20][20];
char X[20];
char Y[20];
int M ;
int N ;
int i,j,c[20][20];



void LCS_LENGTH()
{
	M = strlen(X);
	N = strlen(Y);
	for (i = 0; i <= M; i++)
	{
		c[i][0] = 0;
	}
	for (j = 0; j <=N; j++)
	{
		c[0][ j] = 0;
	}
	for ( i = 1; i <= M; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (X[i-1] == Y[j-1])
			{
				c[i][j] =c[i - 1][ j - 1] + 1;
				b[i][j] = 'D';     
			}
			else if (c[i - 1][j] >= c[i][ j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = 'U';     
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = 'L';   
			}
		}
	}
}

void PRINT_LCS(int i, int j)
{
	if (i == 0 || j == 0)
	{
		return;
	}
	else if (b[i][j] == 'D')
	{
		PRINT_LCS(i - 1, j - 1);
		cout << X[i - 1];
	}
	else if (b[i][j] == 'U')
	{
		PRINT_LCS(i - 1, j);
	}
	else
	{
		PRINT_LCS(i, j - 1);
	}
}



int main()
{
	cout << "Please enter the first sequence: " << endl;
	cin.getline(X,20);
	cout << "Please enter the second sequence: " << endl;
	cin.getline(Y,20);
	cout << "The longest Common subsequence is :";
	LCS_LENGTH();
	PRINT_LCS(M, N);
	return 0;
}
