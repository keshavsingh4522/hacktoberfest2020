#include <bits/stdc++.h>
using namespace std;
int rev(int);
int main()
{
	int n;
	cin>>n;
	cout<<"Reverse of the "<<n<<"is :"<<rev(n)<<endl;
	return 0;
}
int rev(int n)
{
	int sum=0;
	while(n!=0)
	{
		sum += (n%10);
		n /= 10;
	}
	return sum;
}
