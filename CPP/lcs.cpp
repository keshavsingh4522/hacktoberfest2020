#include<bits/stdc++.h>

using namespace std; 


void lcs( char *X, char *Y, int m, int n ) 
{ int count=0;
int L[m+1][n+1]; 
for (int i=0; i<=m; i++) 
{    
	for (int j=0; j<=n; j++) 
	{ //count++;
	if (i == 0 || j == 0) 
		L[i][j] = 0; 
	else if (X[i-1] == Y[j-1]) 
	{   count++;
	
		L[i][j] = L[i-1][j-1] + 1; }
	else
		L[i][j] = max(L[i-1][j], L[i][j-1]); 
	} 
} 

int index = L[m][n]; 

char lcs[index+1]; 
lcs[index] = '\0';
int i = m, j = n; 
while (i > 0 && j > 0) 
{ 
	if (X[i-1] == Y[j-1]) 
	{ 
		lcs[index-1] = X[i-1];  
		i--; j--; index--;	 
	} 

	else if (L[i-1][j] > L[i][j-1]) 
		i--; 
	else
		j--; 
} 

cout << "\nLCS of " << X << " and " << Y << " is " << lcs<<endl; 
cout<<count;
} 

int main() 
{ 
char X[] = "1 1 0 1 0 1 "; 
char Y[] = "0 1 0 0 1 1 0"; 

int m = strlen(X); 
int n = strlen(Y); 
cout<<"Inputs to be used are- "<<endl;
cout<<"First sequence - ";
puts(X);
cout<<"Second sequence - ";
puts(Y);
lcs(X, Y, m, n); 
return 0; 
} 

