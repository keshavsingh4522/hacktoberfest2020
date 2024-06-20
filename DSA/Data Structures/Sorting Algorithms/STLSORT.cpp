#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
cin>>n;
	vector<int> a(n);
for(int &elem : a)
cin>>elem;
sort(a.begin(),a.end());
for(int elem : a){
cout<<elem<<" ";
return 0;

}