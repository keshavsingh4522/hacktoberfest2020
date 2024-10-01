#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<bits/stdc++.h>

using namespace std;



main()
{
	int n,i;
	int arr[100];
	cin>>n;
	
	for(i=0;i<n;i++)
	cin>>arr[i];
	
	for(i=0;i<n;i++)
	{
		if(arr[abs(arr[i])-1]<0)cout<<abs(arr[abs(arr[i])-1])<<" ";
		else
		arr[abs(arr[i])-1]=-arr[abs(arr[i]-1)];
	}
	for(i=0;i<n;i++)
	//cout<<arr[i]<<" ";
if(arr[i]>0)cout<<i+1<< " ";

return 0;
}


