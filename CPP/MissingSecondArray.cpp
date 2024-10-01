#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	
	public:
	int binary_search(long long b[], int beg, int end, long long elem)
	{
	    if(beg<=end)
	    {
	        int mid=(beg+end)/2;
	        if(b[mid]==elem)
	        return mid;
	        else if(b[mid]<elem)
	        return binary_search(b,mid+1,end,elem);
	        else
	        return binary_search(b,beg,mid-1,elem);
	    }
	    else 
	    return -1;
	}
	vector<long long> findMissing(long long a[], long long b[],  
                 int N, int M) 
	{ 
	    // Your code goes here
	    sort(b,b+M);
	    vector<long long> vec;
	    for(int i=0;i<N;i++)
	    {
	    int ans=binary_search(b,0,M-1,a[i]);
	    if(ans==-1)
	    vec.push_back(a[i]);
	    }
	    return vec;
	} 
};
	

// { Driver Code Starts.

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
        cin>>n;
        int m;
        cin>>m;
        long long a[n];
        long long b[m];
        for(int i=0;i<n;i++)
        cin>>a[i];
        for(int i=0;i<m;i++)
        cin >> b[i];
        vector<long long> ans;
        

        Solution ob;
        ans=ob.findMissing(a,b,n,m);
        for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
	    
        
	    cout << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends