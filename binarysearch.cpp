
#include <iostream>
using namespace std;

void binarysearch( int a[],int n, int data){
	int l,u,m;
	l=0;
	u=n-1;
	while(l<=u){
		m=(l+u)/2;
		if(a[m]==data){
			cout << "element found at "<<m;
			return;
		}
		else if(data<a[m]){
			u=m-1;
		}
		else if(data >a[m]){
			l=m+1;
		}
	}
	cout << "element not found";
}



int main() {

	int a[]={1,45,67,89,91,99,100 ,123,321,445};
	binarysearch(a,10,445);
	return 0;
}
