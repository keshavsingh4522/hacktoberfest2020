#include <bits/stdc++.h>
using namespace std;

void minheapify(int a[], int i, int n){
	int smallest = i;
	int l = (2*i) + 1;
	int r = (2*i) + 2;
	
	if(l<n && a[l]<a[smallest]){
		smallest = l;
	}
	
	if(r<n && a[r]<a[smallest]){
		smallest = r;
	}
	
	if(smallest != i){
		int temp = a[i];
		a[i] = a[smallest];
		a[smallest] = temp;
		minheapify(a,smallest,n);
	}
}

void buildminheap(int a[], int n){
	for(int i=(n/2)-1;i>=0;i--){
		minheapify(a,i,n);
	}
}

void minheapsort(int a[], int n){
	buildminheap(a,n);
	
	for(int i=n-1;i>=0;i--){
		swap(a[0], a[i]);
		minheapify(a,0,i);
	}
}

void printarray(int a[], int n){
	for(int i=0;i<n;++i){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int n;
	cout<<"enter the no of elements :";
	cin>>n;
	int a[n];
	srand(time(0));
	for(int i=0;i<n;i++)
	    a[i] = 1 + rand()%15;
	cout<<"Random numbers inserted into the array\n";
	
	cout<<"\nDisplay array: ";
	printarray(a,n);
	
	cout<<"\nSorted array in descending order using min-heap algo: \n";
	minheapsort(a,n);
	printarray(a,n);
	
	return 0;
}
	