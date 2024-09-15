#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define ull unsigned long long int	
#define mod 1000000007
 
// sort(arr, arr + n);
 
int main() {
    //ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	ull n;
	cin>>n;
	cout<<n<<" ";
 
	while(n != 1)
	{
 
		if((n&1) != 0)
		{
			//odd
			n = (n*3)+1;
			cout<<n<<" ";
		}
		else
		{
			//even
			n = (n/2);
			cout<<n<<" ";
		}
	}
	
 
	
	return 0;
}
