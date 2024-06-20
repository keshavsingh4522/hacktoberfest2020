// C++ Program to implement
// the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to return the length
// of longest subarray forming an AP
int getMaxLength(int arr[], int N)
{
	//single number is also an AP
	//with common difference as 0
	if(N==1)
	return 1;

	// Minimum possible length of
	// required subarray is 2
	int res = 2;

	// Stores the length of the
	// current subarray
	int dist = 2;

	// Stores the common difference
	// of the current AP
	int curradj = (arr[1] - arr[0]);

	// Stores the common difference
	// of the previous AP
	int prevadj = (arr[1] - arr[0]);
	for (int i = 2; i < N; i++) {
		curradj = arr[i] - arr[i - 1];

		// If the common differences
		// are found to be equal
		if (curradj == prevadj) {

			// Continue the previous subarray
			dist++;
		}

		// Start a new subarray
		else {
			prevadj = curradj;

			// Update the length to
			// store maximum length
			res = max(res, dist);
			dist = 2;
		}
	}

	// Update the length to
	// store maximum length
	res = max(res, dist);

	// Return the length of
	// the longest subarray
	return res;
}

// Driver Code
int main()
{
	int arr[] = {10, 7, 4, 6, 8, 10, 11};
	int N = sizeof(arr) / sizeof(arr[0]);
	cout << getMaxLength(arr, N);
}
