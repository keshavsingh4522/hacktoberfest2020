/*
First Repeating Element 
Given an array arr[] of size N. The task is to find the first repeating element in an array of integers, i.e., an element that occurs more than once and whose index of first occurrence is smallest.

Example 1:

Input:
7
1 5 3 4 3 5 6

Output: 
2

Explanation: 
5 is appearing twice and 
its first appearence is at index 2 
which is less than 3 whose first 
occuring index is 3.
Example 2:

Input:
4
1 2 3 4

Output: 
-1

Explanation: 
All elements appear 
only once so -1 is printed.
Input :
The first line contains an integer T denoting the total number of test cases. In each test cases, First line is number of elements in array N and second its values.

Your Task:
Complete firstRepeated() function and return the index of first repeated element, if there is not any repeating element then return “-1” (without quotes). Use 1 Based Indexing.

Constraints:
1 <= N <= 106
0 <= Ai <= 106

Expected Time Complexity : O(NlogN)
Expected Auxilliary Space : O(N)
*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code Shokeen
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    map<int,int> mp;
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	        mp[arr[i]]++;
	    }
	    int i=0;
	    for(i=0;i<n;i++)
	    {
	        if(mp[arr[i]]>=2)
	          { 
	              cout<<i+1<<endl;
	              break;
	          }
	    }
	    if(i==n)
	     cout<<"-1"<<endl;
	    
	 }
	return 0;
}
