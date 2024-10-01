#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
       

int ans =0;
      for(int  i=1;i< 32;i++){
       if(n >= pow(2,i-1))
              ans = ans +  ((n -(int)(pow(2,i-1)-1))/(int)pow(2,i))*(int)pow(2,i)/2 + min((n -((int)pow(2,i-1)-1))%(int)pow(2,i) ,(int)pow(2, i-1) ) ;       
      }
      return ans ;
    }
};


// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends