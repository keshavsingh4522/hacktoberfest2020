/*
Min Steps to 1 using DP
Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. 
You can perform any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - 1) ,
2.) If n is divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If n is divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  

Input format :
The first and the only line of input contains an integer value, 'n'.

Output format :
Print the minimum number of steps.

Constraints :
1 <= n <= 10 ^ 6

Time Limit: 1 sec

Sample Input 1 :
4

Sample Output 1 :
2 

Explanation of Sample Output 1 :
For n = 4
Step 1 :  n = 4 / 2  = 2
Step 2 : n = 2 / 2  =  1 


Sample Input 2 :
7

Sample Output 2 :
3

Explanation of Sample Output 2 :
For n = 7
Step 1 :  n = 7 - 1 = 6
Step 2 : n = 6  / 3 = 2 
Step 3 : n = 2 / 2 = 1  
*/

#include<vector>
int countStepsToOne(int n) {
	
    vector<int> minCount(n + 1);
    minCount[1] = 0;
    
    for(int i = 2; i < n + 1; i++) {
    	if(i % 2 != 0 and i % 3 == 0) {
            minCount[i] = 1 + min(minCount[i - 1], minCount[i / 3]);
        } else if (i % 2 == 0 and i % 3 != 0) {
            minCount[i] = 1 + min(minCount[i - 1], minCount[i / 2]);
        } else if(i % 2 == 0 and i % 3 == 0) {
            minCount[i] = 1 + min(minCount[i - 1], min(minCount[i / 2], minCount[i / 3]));
        } else {
            minCount[i] = 1 + minCount[i - 1];
        }
    }
    
    return minCount[n];
}

// Dynamic Programming
// Time Complexity : O(n)
// Auxillary Space : O(n)
