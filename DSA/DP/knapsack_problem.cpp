//Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 

#include <bits/stdc++.h>
using namespace std;
int knapSack(int wei, int wt[], int val[], int n)
{
	int dp[wei + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i < n + 1; i++) {
		for (int w = wei; w >= 0; w--) {

			if (wt[i - 1] <= w)
				// finding the maximum value
				dp[w] = max(dp[w],
							dp[w - wt[i - 1]] + val[i - 1]);
		}
	}
	return dp[wei];
}
int main()
{
	int val[] = { 450, 260, 110 };
	int wt[] = { 100, 280, 530 };
	int wei = 50;
	int n = sizeof(val) / sizeof(val[0]);
	cout << knapSack(wei, wt, val, n);
	return 0;
}
