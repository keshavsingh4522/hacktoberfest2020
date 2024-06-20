#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	int arr[10];//3 1 2 3 2 4 1 
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    
    unordered_map<int,int>m;
    
    for(int i=0;i<n;i++)
    {
        m[arr[i]]++;
    }
    
    for(auto i :m)
    {
        if(i.second==1)
        cout<<i.first;
    }
	
	return 0;
}
