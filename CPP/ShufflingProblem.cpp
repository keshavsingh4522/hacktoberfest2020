#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=1; i<=t; i++)
	{

		int n;
		cin>>n;
		int a[n];
		int od=0;
		for(int i=0 ; i<n; i++)
		{
			cin>>a[i];
			if(a[i] % 2 != 0)
				od++;
		}
		int m = (n/2);
		int sum = n - abs(m - od);
		cout<<sum<<'\n';

	}

	return 0;
}
