class Solution {
public:
    bool isPalindrome(string s) {
        int l=0,r=s.size()-1;
        while(l<r)
        {
            if(!isalnum(s[l])){
                l++;
            }
            else if(!isalnum(s[r])){
                r--;
            }
            else if(tolower(s[l])!=tolower(s[r])){
                return false;
            }
            else{
                l++;
                r--;
            }
        }
        return true;
    }
};
// { Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	
	int isPlaindrome(string S)
	{
	    int l=0;
	    int r=S.size()-1;
	    while(l<r){
	        if(S[l]!=S[r]) return 0;
	        l++;
	        r--;
	    }
	    return 1;
	}

};

// { Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPlaindrome(s) << "\n";
   	}

    return 0;
}  // } Driver Code Ends