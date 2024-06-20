// Also known as Gravity sort, this algorithm was inspired from natural phenomenon and was designed keeping in mind objects(or beads) falling under the influence of gravity.

// The Idea: Positive numbers are represented by a set of beads like those on an abacus.

// Time Complexity:
// The algorithm’s run–time complexity ranges from O(1) to O(S) (S is the sum of the input integers) depending on the user’s perspective. Finally, three possible implementations are suggested.

// O(1) : Dropping all beads together as a single (simultaneous) operation. This complexity cannot be implemented in practice.
// O(n^1/2): In a realistic physical model that uses gravity, the time it takes to let the beads fall is proportional to the square root of the maximum height, which is proportional to n.
// O(n) : Dropping the row of beads in the frame (representing a number) as a distinct operation since the number of rows is equal to n.
// O(S) : Dropping each and every bead’ as a separate operation since S is the sum of all the beads.
// Like the Pigeonhole sort, bead sort is unusual in that in worst case it can perform faster than O(n log n), the fastest performance possible for a comparison sort in worst case. This is possible because the key for a bead sort is always a positive integer and bead sort exploits its structure.

// Space Complexity: Bead sort is the record-holder as for waste. The costs for the extra memory exceed the costs for storing the array itself. Its memory complexity is O(n^2)

#include <bits/stdc++.h>
using namespace std;

#define BEAD(i, j) beads[i * max + j]

void beadSort(int *a, int len)
{
	// Find the maximum element
	int max = a[0];
	for (int i = 1; i < len; i++)
		if (a[i] > max)
		max = a[i];

	// allocating memory
	unsigned char beads[max*len];
	memset(beads, 0, sizeof(beads));

	// mark the beads
	for (int i = 0; i < len; i++)
		for (int j = 0; j < a[i]; j++)
			BEAD(i, j) = 1;

	for (int j = 0; j < max; j++)
	{
		// count how many beads are on each post
		int sum = 0;
		for (int i=0; i < len; i++)
		{
			sum += BEAD(i, j);
			BEAD(i, j) = 0;
		}

		// Move beads down
		for (int i = len - sum; i < len; i++)
			BEAD(i, j) = 1;
	}

	// Put sorted values in array using beads
	for (int i = 0; i < len; i++)
	{
		int j;
		for (j = 0; j < max && BEAD(i, j); j++);

		a[i] = j;
	}
}

// driver function to test the algorithm
int main()
{
	int a[] = {5, 3, 1, 7, 4, 1, 1, 20};
	int len = sizeof(a)/sizeof(a[0]);

	beadSort(a, len);

	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);

	return 0;
}
