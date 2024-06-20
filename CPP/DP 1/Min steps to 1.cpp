/*
Min Steps to 1
Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. 
You can perform any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - 1) ,
2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  
Write brute-force recursive solution for this.

Input format :
The first and the only line of input contains an integer value, 'n'.

Output format :
Print the minimum number of steps.

Constraints :
1 <= n <= 200

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

#include<climits>
#include<vector>
/*
int countMinStepsToOne(int n) {
	//Write your code here
    // Base Case
    if(n == 1) {
        return 0;
    }
    
    int x = countMinStepsToOne(n - 1);
    int y = INT_MAX;
    int z = INT_MAX;
   
    if(n % 2 == 0) {
        y = countMinStepsToOne(n / 2);
    } 
    
    if(n % 3 == 0) {
        z = countMinStepsToOne(n / 3);
    }
    
    
    return min(x, min(y, z)) + 1;
}
// Brute Force Approach
// Time Complexity : O(2^n) (Average Case) || NOTE : In the worst case : O(3^n)
// Auxillary Space : O(n)
*/

/*******************************Memoization*******************************/


int helper(vector<int>& minCount, int n) {
    // base case
    if(n == 1) {
        return 0;
    }
    
    if(minCount[n] != -1) {
        return minCount[n];
    }
    
    int answer = helper(minCount, n - 1);
    
    if(n % 2 == 0) {
        answer = min(answer, helper(minCount, n / 2));
    }
    
    if(n % 3 == 0) {
        answer = min(answer, helper(minCount, n / 3));
    }
    
    minCount[n] = 1 + answer;
    
    return minCount[n];
}

int countMinStepsToOne(int n) {
    vector<int> minCount(n + 1);
    
    for(int i = 0; i < n + 1; i++) {
        minCount[i] = -1;
    }
    
    return helper(minCount, n);
}
// Time Complexity : O(n)
// Auxillary Space : O(n);
