#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s1="hello";
	string s2="world";
//	getline(cin,s);
	cout<<"length of the string is: "<<s1.length();
	
	//iterating over characters
	for(int i=0;i<s1.length();i++)
	cout<<s1[i]<<endl;
	
	//using iterators
	for(auto itr=s1.begin();itr!=s1.end();itr++)
	cout<<(*itr)<<endl;
	
	//using for each loop
	for(auto x:s1)
	cout<<x<<endl;
	return 0;
}
