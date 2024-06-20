/*
No. of balanced BTs
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Write a simple recursive solution.

Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.

Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.

Constraints :
1 <= h <= 24

Time Limit: 1 sec

Sample Input 1:
3

Sample Output 1:
15


Sample Input 2:
4

Sample Output 2:
315
*/

#define mod 1000000007
long balancedBTs(int n) {
    // Write your code here
    // base case 
    if(n == 0 or n == 1) {
        return 1;
    }
    
    long smalloutput1 = balancedBTs(n - 1);
    long smalloutput2 = balancedBTs(n - 2);
    
    return ((smalloutput1 % mod) * ((2 * smalloutput2) + smalloutput1) % mod) % mod;
}

// Time Complexity : O(2 ^ n)
// Auxillary Space : O(n)
