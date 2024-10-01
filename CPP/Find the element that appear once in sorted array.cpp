#include <bits/stdc++.h>
using namespace std;

// A Linear Search based function to find
// the element that appears only once
void search(int arr[], int n)
{
	int ans = -1;
	for (int i = 0; i < n; i += 2) {
		if (arr[i] != arr[i + 1]) {
			ans = arr[i];
			break;
		}
	}

	if (arr[n - 2] != arr[n - 1])
			ans = arr[n-1];

	// ans = -1 if no such element is present.
	cout << "The required element is " << ans << "\n";
}

// Driver code
int main()
{
	int arr[] = { 1, 1, 2, 4, 4, 5, 5, 6, 6 };
	int len = sizeof(arr) / sizeof(arr[0]);

	search(arr, len);

	return 0;
}
