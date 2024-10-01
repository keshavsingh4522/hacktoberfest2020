#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pi[1000005];

int main()
{
	string p,t;
	cin>>p>>t;
	string st=p+"#"+t;
	pi[0]=0;
	for(ll i=1;i<st.size();i++)   //pi calculator
	{
		ll j=pi[i-1];
		while(j>0&&st[i]!=st[j])
		j=pi[j-1];

		if(st[i]==st[j])
		j++;
		pi[i]=j;
	}
	ll ans=0;
	for(ll i=p.size();i<st.size();i++)
	if(pi[i]==p.size())
	ans++;

	cout<<ans;

	return 0;
}