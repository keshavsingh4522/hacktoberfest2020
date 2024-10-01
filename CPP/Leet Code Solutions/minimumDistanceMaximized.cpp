#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;

bool check(lld mid, vector<lld>a, lld N, lld K)
{
    lld i=a[0], n=1;
    
    for(int j=1; j<N; j++)
    {
        if(a[j]-i>=mid)
        {
            i=a[j];
            n++;
            
            if(n==K)
                return true;
        }
    }
    return false;
}

int main() 
{
	lld N, K;
	cin>>N>>K;
	
	vector<lld>a;
	for(lld i=0; i<N; i++)
	{
	    lld x; cin>>x;
	    a.push_back(x);
	}
	
	sort(a.begin(), a.end());
	vector<lld>::iterator it;
	it=unique(a.begin(), a.begin()+N);
	a.resize(distance(a.begin(), it));
	
	lld ans=-1;
	N=a.size();
	if(N<K)
	{
	    cout<<ans;
	    return 0;
	}
	
	lld left=1, right=a[N-1]-a[0];
	while(left<right)
	{
	    lld mid=left+(right-left)/2;
	    if(check(mid, a, N, K))
	    {
	        ans=max(ans, mid);
	        left=mid+1;
	    }
	    else right=mid;
	}
	
	cout<<ans;
	return 0;
}
