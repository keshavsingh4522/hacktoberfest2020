/*
Loot Houses
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.

Input format :
The first line of input contains an integer value of 'n'. It is the total number of houses.
The second line of input contains 'n' integer values separated by a single space denoting the amount of money each house has.

Output format :
Print the the maximum money that can be looted.

Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec

Sample Input 1 :
6
5 5 10 100 10 5

Sample Output 1 :
110


Sample Input 2 :
6
10 2 30 20 3 50

Sample Output 2 :
90

Explanation of Sample Output 2 :
Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot, and all the other possible combinations would result in less than 90.
*/

#include<vector>
int maxMoneyLooted(int *arr, int n) {
	vector<int> dp(n + 1);
    dp[0] = 0;
    for(int i = 1; i < n + 1; i++) {
    	if(i == 1) {
            dp[i] = arr[0];
        } else {	
        	dp[i] = max(arr[i - 1] + dp[i - 2], dp[i - 1]);
        }
    }
    
    return dp[n];
}

// Dynamic Programming
// Time Complexity : O(n)
// Auxillary Space : O(n)
