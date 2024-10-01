// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to maximize the value of the
// function by choosing at most K elements
// from the given array
int maximumValue(int arr[], int powr[],
				int K, int N)
{

	// Vector to store the power of elements
	// along with the elements in pair
	vector<pair<int, int> > v(N);

	// In a pair, the first position contains
	// the power and the second position
	// contains the element
	for (int i = 0; i < N; i++) {
		v[i].first = powr[i];
		v[i].second = arr[i];
	}

	// Sort the vector according to the
	// power of the elements
	sort(v.begin(), v.end());

	// Variable to store the answer
	int res = 0;

	// Variable to store the sum of
	// elements
	int sum = 0;

	// Create a set of pairs
	set<pair<int, int> > s;

	// Traverse the vector in reverse order
	for (int i = N - 1; i >= 0; i--) {

		// Insert the element along with the
		// index in pair
		s.insert(make_pair(v[i].second, i));
		sum += v[i].second;

		// If size of set exceeds K, then
		// delete the first pair in the set
		// and update the sum by excluding
		// the elements value from it
		if (s.size() > K) {
			auto it = s.begin();
			sum -= it->first;
			s.erase(it);
		}

		// Store the maximum of all sum
		// multiplied by the element's
		// power
		res = max(res, sum * v[i].first);
	}

	// Return res
	return res;
}

// Driver Code
int main()
{
	int arr[] = { 11, 10, 7, 6, 9 };
	int powr[] = { 3, 2, 4, 1, 1 };
	int K = 2;

	int N = sizeof(arr) / sizeof(arr[0]);
	cout << maximumValue(arr, powr, K, N);

	return 0;
}
