/*
Largest subarray with 0 sum 
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
Your Task:
You just have to complete the function maxLen() which takes two arguments an array A and n, where n is the size of the array A and returns the length of the largest subarray with 0 sum.

Expected Time Complexity: O(N*Log(N)).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 104
-1000 <= A[i] <= 1000, for each valid i
*/


#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}
// } Driver Code Ends
/*You are required to complete this function*/
int maxLen(int A[],int n)
{
    int res  = 0;
    unordered_map<int, int> m;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum = sum + A[i];
        if(sum == 0)
            res = i+1;
        
        if(m.find(sum) != m.end())
        {
            res = max((i-(m.find(sum)->second)), res);
        }
        m.insert(make_pair(sum,i));
    }
    return res;
}

