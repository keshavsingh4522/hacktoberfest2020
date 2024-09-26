#include <bits/stdc++.h>
using namespace std;
class Solution{
		

	public:
	int maxSumIS(int a[], int n)  
	{  
	    int lis[n];
	    for(int i=0;i<n;i++)
	    lis[i]=a[i];
	    for(int i=1;i<n;i++)
	    {
	        for(int j=0;j<i;j++)
	        {
	            if(a[i]>a[j]&&lis[i]<lis[j]+a[i])
	            lis[i]=lis[j]+a[i];
	        }
	    }
	    return (*max_element(lis,lis+n));
	}  
};
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}
