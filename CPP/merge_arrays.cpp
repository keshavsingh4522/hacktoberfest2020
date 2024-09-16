// C++ program to merge k sorted arrays of size n each.
#include<bits/stdc++.h>
using namespace std;
#define n 4


// A utility function to print array elements
void printArray(int arr[], int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}

// This function takes an array of arrays as an argument and
// All arrays are assumed to be sorted. It merges them together
// and prints the final sorted output.
void mergeKArrays(int arr[][n], int a, int output[])
{
	int c=0;
	
	//traverse the matrix
	for(int i=0; i<a; i++)
	{
		for(int j=0; j<n ;j++)
			output[c++]=arr[i][j];
	}
	
	//sort the array
	sort(output,output + n*a);
	
}


// Driver program to test above functions
int main()
{
	// Change n at the top to change number of elements
	// in an array
	int arr[][n] = {{2, 6, 12, 34},
					{1, 9, 20, 1000},
					{23, 34, 90, 2000}};
	int k = sizeof(arr)/sizeof(arr[0]);
	
	int output[n*k];
	
	mergeKArrays(arr, 3, output);

	cout << "Merged array is " << endl;
	printArray(output, n*k);

	return 0;
}
