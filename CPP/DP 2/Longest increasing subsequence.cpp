/*
Longest Increasing Subsequence
Given an array with N elements, you need to find the length of the longest subsequence in the given array such that all elements of 
the subsequence are sorted in strictly increasing order.

Input Format
The first line of input contains an integer N. The following line contains N space separated integers, that denote the value of elements of array.

Output Format
The first and only line of output contains the length of longest subsequence.

Constraints
1 <= N <= 10^3

Time Limit: 1 second

Sample Input 1 :
6
5 4 11 1 16 8

Sample Output 1 :
3

Sample Output Explanation
Length of longest subsequence is 3 i.e. (5,11,16) or (4,11,16).


Sample Input 2 :
3
1 2 2

Sample Output 2 :
2
*/

/*********************************** Optimised ***********************************/
#include<bits/stdc++.h>

int solve(vector<int>& nums) {
    vector<int> lis;
     
    
    for(auto it : nums) {
        auto it2 = lower_bound(lis.begin(), lis.end(), it);   
        // upper_bound for longest non decreasing subsequence
    	// lower_bound for longest increasing subsequence
        if(it2 == lis.end()){
            lis.push_back(it);
        } else {
            *it2 = it;
        }
    }
    return lis.size();
}

int longestIncreasingSubsequence(int* arr, int n) {
    vector<int> nums(n);
    
    for(int i = 0; i < n; i++) {
        nums[i] = arr[i];
    }
    
    return solve(nums);
}
// Time Complexity : O(nlogn) 
// Auxillary Space : O(n)

/*********************************** DP ***********************************/
/*
#include<vector>
#include<algorithm>
int longestIncreasingSubsequence(int* arr, int n) {
	// Write your code here
    vector<int> dp(n);
    dp[0] = 1;
    for(int i = 1; i < n; ++i) {
        dp[i] = 1;
    	for(int j = i - 1; j >= 0; --j) {
            if(arr[j] >= arr[i]) {
                continue;
            } else {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }
    
    return *max_element(dp.begin(),dp.end());  
}
// Dynamic Programming
// Time Complexity : O(n^2)
// Auxillary Space : O(n)
*/
