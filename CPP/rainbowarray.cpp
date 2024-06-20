 #include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int arr[N];
	    for(int i = 0;i<N;i++){
	        cin>>arr[i];
	    }
	    int p1 = 0,p2 = N-1,flag = 1;
	    if(arr[p1]!=1){
	     flag = 0;
	    }
	    else{
	        while(p1<p2){
	            if(arr[p1]!=arr[p2]){
	                flag = 0;
	                break;
	            }
	            if(arr[p1]!=arr[p1+1]&&arr[p1]+1!=arr[p1+1]){
	                flag = 0;
	                break;
	            }
	            p1 += 1;
	            p2 -= 1;
	        }
	        if(arr[p1]!=7)
	         flag = 0;
	    }
	    if(flag==1)
	     cout<<"yes"<<endl;
	    else
	     cout<<"no"<<endl;
	}
	return 0;
}/*
An array is Rainbow if it has the following structure:

First a1 elements equal 1.
Next a2 elements equal 2.
Next a3 elements equal 3.
Next a4 elements equal 4.
Next a5 elements equal 5.
Next a6 elements equal 6.
Next a7 elements equal 7.
Next a6 elements equal 6.
Next a5 elements equal 5.
Next a4 elements equal 4.
Next a3 elements equal 3.
Next a2 elements equal 2.
Next a1 elements equal 1.
ai can be any non-zero positive integer.
There are no other elements in array.


*/