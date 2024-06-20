#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main(){
	int n ;
	cin>>n;
	
	char a[100];
	char largest[100];
	
	int len = 0;
	int largest_len = 0;
	
	cin.get();
	for( int i = 0 ;i<n ; i++){
		cin.getline(a,100);
		len = strlen(a);
		if(len>largest_len){
		   largest_len = len;
			
			strcpy(largest,a);
		}
	}
	
	cout<<"Largest is "<<largest<<" with :- "<<largest_len<<"\n";
	return 0;
}
