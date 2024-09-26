/*
Majority Element 
Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.

Input:  
The first line of the input contains T denoting the number of testcases. The first line of the test case will be the size of array and second line will be the elements of the array.

Output: 
For each test case the output will be the majority element of the array. Output "-1" if no majority element is there in the array.

Constraints:
1 <= T<= 100
1 <= N <= 107
0 <= Ai <= 106

Example:
Input:
2
5
3 1 3 3 2
3
1 2 3

Output:
3
-1

Explanation:
Testcase 1: Since, 3 is present more than N/2 times, so it is the majority element.
*/


/*
//O(n) time and space
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;unordered_map<int,int>m;
	    int f=1;
	    int a[n];
	    for(int i=0;i<n;i++)
	     {cin>>a[i];
	     m[a[i]]++;}
	     for(auto i:m)
	     if(i.second>(n/2))
	      {cout<<i.first<<endl;f=0;
	      break;}
	     if(f)
	     cout<<-1<<endl;
	}
	return 0;
}*/

//O(nlogn) time and O(1) space
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,c=1,p;
	    cin>>n;
	    int f=0;
	    int a[n];
	    for(int i=0;i<n;i++)
	     {cin>>a[i];}
	     sort(a,a+n);
	    for(int i=0;i<n-1;i++)
	    {
	        if(a[i]==a[i+1])
	         c++;
	        else 
	        c=1;
	        if(c>(n/2))
	         { p=a[i];f=1;break;}
	        
	    }
	    if(f)
	    cout<<p<<endl;
	    else
	     cout<<-1<<endl;
	}
	return 0;
}

