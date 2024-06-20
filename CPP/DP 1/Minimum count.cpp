/*
Minimum Count
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers 
required to represent N as sum of squares.

Input format :
The first and the only line of input contains an integer value, 'N'.

Output format :
Print the minimum count of numbers required.

Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec

Sample Input 1 :
12

Sample Output 1 :
3

Explanation of Sample Output 1 :
12 can be represented as : 
A) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)

B) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)  + (2 ^ 2)

C) (1^2) + (1^2) + (1^2) + (1^2) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.


Sample Input 2 :
9

Sample Output 2 :
1
*/

/*******************************Dynamic Programming*******************************/
int minCount(int n) {
    if(sqrt(n) == floor(sqrt(n))) {
        return 1;
    }
    
    vector<int> dp(n + 1);
    
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i = 2 ; i < n + 1 ; i++) {
        int min = i; // The maximum number of squares to reach any numbers will that be of 1's
        for(int j = 1; j * j <= i; j++) {
            int remaining = i - j * j;  // We removed the j^2 from i 
            if(dp[remaining] < min) {
                min = dp[remaining];
            }
        }
        dp[i] = 1 + min;
    }
    return dp[n];
}

// Time Complexity : O(nsqrtn)
// Auxillary Space : O(n)


/*******************************Memoization*******************************/
/*
int helper(vector<int>& memoize, int n) {
     // Base Cases
    if(sqrt(n) == floor(sqrt(n))) {
        memoize[n] = 1;
        return memoize[n];
    }
    
    // For n <= 3 we will have only 1's squares
    if(n <= 3) {
        memoize[n] = n;
        return memoize[n];
    }
    
    if(memoize[n] != -1) {
        return memoize[n];
    }
	
    int ans = n;
    for(int i = 1; i * i <= n; i++) {
        memoize[n] = ans = min(ans, 1 + helper(memoize, n -  i*i)); 
    }
    
    return memoize[n];
    
}

int minCount(int n) {
    vector<int> memoize(n + 1);
    for(int i = 0; i < n + 1; i++) {
        memoize[i] = -1;
    }
    
    return helper(memoize, n);
}

// Time Complexity : O(nsqrt(n))
// Auxillary Space : O(n)
*/

/*
int minCount(int n){
	//Write your code here
    // Base Cases
    if(sqrt(n) == floor(sqrt(n))) {
        return 1;
    }
    
    // For n <= 3 we will have only 1's squares
    if(n <= 3) {
        return n;
    }
    
    // The maximum number of squares for a number n can be n i.e sum of 1's
    int count = n;
    
    for(int i = 1; i * i <= n; i++) {
        count = min(count, 1 + minCount(n - i * i));
    }
    
    return count;
}

// Brute Force Approach
// Time Complexity : Exponential Complexity -> For every n we call the function for 
// Auxillary Space : O(n)
*/
