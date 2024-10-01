#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,d;
	    cin>>n>>d;
	    int k=n,rem=0,ans=0,c=0;
	    while(k>0){
	        rem = k%10;
	        k = k/10;
	        c++;
	        if(rem==d){
	            k = k*pow(10,c)+(rem+1)*pow(10,c-1);
	            ans=k-n;
	            c=0;
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
