#include <iostream>
using namespace std;

int main() {
	// your code goes here
	long long t;
	cin >> t;
	while(t--){
	    long long int n,a,b;
	 cin>>n>>a>>b;
	 long long int low=0;
	 long long int high=max(a,b)*n;
	 long long int res=0;
	 while(low<=high)
	 {
	 	  long long int mid=low+(high-low)/2;
	 	  long long int count=(mid/a)*(mid/b);
	 	  if(count>=n)
	 	  {
	 	  	res=mid;
	 	  	high=mid-1;
	 	  }
	 	  else
	 	  	   low=mid+1;
	 }
	 cout<<res<<"\n";
	}
	return 0;
}