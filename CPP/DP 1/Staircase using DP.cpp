/*
Staircase using Dp
A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count and return 
all possible ways in which the child can run-up to the stairs.

Input format :
The first and the only line of input contains an integer value, 'n', denoting the total number of steps.

Output format :
Print the total possible number of ways.

Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec

Sample Input 1:
4

Sample Output 1:
7


Sample Input 2:
10

Sample Output 2:
274
*/

#include<vector>
long staircase(int n) {
	vector<long> totalPathCount(n + 1);
    if(n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else if(n >= 3) {
    	totalPathCount[1] = 1;
   	 	totalPathCount[2] = 2;
    	totalPathCount[3] = 4;
    
    	for(int i = 4; i < n + 1; i++) {
        	totalPathCount[i] = totalPathCount[i - 1] + totalPathCount[i - 2] + totalPathCount[i - 3];
      }
    	return totalPathCount[n];
    }
}

// Dynamic Programming
// Time Complexity : O(n)
// Auxillary Space : O(n)
