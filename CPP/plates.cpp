#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
 
 
 
 int getSum(int stack , int plates , int** s)
 {
 
 	int sum =0 ;
 	for(int i =0 ; i< plates ; i++)
 	{
 		sum = sum + s[stack][i];
 	}
 	return sum;
 
 }
 
 
 int main()
 {
 
 int stackCount;
 int plateCount;
 int stackSize;
 int maxBeauty = 0;
 
  cout<< "Enter the Stack Count"<< "\n";
 cin>> stackCount;
  cout << endl;
  cout<< "Enter the stack size" <<"\n";
 cin>>stackSize;
  cout << endl;
 cout<< "Enter the max plates to pick \n";
 cin>> plateCount;
 cout << endl;




cout << "Start entering the beauty values\n";
 int **stacks = new int*[stackCount];
 
 for(int i =0 ; i< stackCount ; i++)
 {
 	stacks[i]= new int[stackSize];        // declared the stack*plates array 
 }
 
 
 for(int i =0 ; i<stackCount; i++)
 {
 	cout << "Enter the stack " << i <<endl;
 	for (int j=0 ; j<stackSize; j++)
 	{
 		cin >> stacks[i][j];				// took the input of the stack and the plates
 	}
 }
 
 
 /*dp[i][j] denotes from the first i stacks I  have chosen j plates with maximum beauty value  */
 
 int **dp = new int*[stackCount];
  for(int i =0 ; i< stackCount ; i++)
 {
 	dp[i]= new int[plateCount];        // declared the stack*plates array  for DP
 }
 

  for(int i =0 ; i< stackCount ; i++)
 {
 	dp[0][i]= 0;          // base condition for the DP
 }
  




 for(int i =1 ; i< stackCount ; i++)
 {
     for(int j=0 ; j<plateCount ; j++)
     {
         dp[i][j] = 0;
			for(int k = 1 ; k<=(min(j , stackSize)) ;k++)
			{
				dp[i][j] = max(dp[i][j] , (getSum(i , k , stacks) + dp[i-1][j - k]));
			}
     }
     
 }

for(int i = 0 ; i< stackCount ; i++)
{
	for(int j =0 ; j <plateCount ; j++)
	{
		cout << dp[i][j];	
	}
	cout <<endl;
}
 
 
 return 0;
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
