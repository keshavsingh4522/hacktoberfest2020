#include <bits/stdc++.h>
using namespace std;

// This function puts all elements of 3 queues in the auxiliary array
void populateAux(int aux[], queue<int> queue0, queue<int> queue1,
				queue<int> queue2, int* top)
{
	// Put all items of first queue in aux[]
	while (!queue0.empty()) {
		aux[(*top)++] = queue0.front();
		queue0.pop();
	}

	// Put all items of second queue in aux[]
	while (!queue1.empty()) {
		aux[(*top)++] = queue1.front();
		queue1.pop();
	}

	// Put all items of third queue in aux[]
	while (!queue2.empty()) {
		aux[(*top)++] = queue2.front();
		queue2.pop();
	}
}

// The main function that finds the largest possible multiple of
// 3 that can be formed by arr[] elements
int findMaxMultupleOf3(int arr[], int size)
{
	// Step 1: sort the array in non-decreasing order
	sort(arr, arr + size);

	// Create 3 queues to store numbers with remainder 0, 1
	// and 2 respectively
	queue<int> queue0, queue1, queue2;

	// Step 2 and 3 get the sum of numbers and place them in
	// corresponding queues
	int i, sum;
	for (i = 0, sum = 0; i < size; ++i) {
		sum += arr[i];
		if ((arr[i] % 3) == 0)
			queue0.push(arr[i]);
		else if ((arr[i] % 3) == 1)
			queue1.push(arr[i]);
		else
			queue2.push(arr[i]);
	}

	// Step 4.2: The sum produces remainder 1
	if ((sum % 3) == 1) {
		// either remove one item from queue1
		if (!queue1.empty())
			queue1.pop();

		// or remove two items from queue2
		else {
			if (!queue2.empty())
				queue2.pop();
			else
				return 0;

			if (!queue2.empty())
				queue2.pop();
			else
				return 0;
		}
	}

	// Step 4.3: The sum produces remainder 2
	else if ((sum % 3) == 2) {
		// either remove one item from queue2
		if (!queue2.empty())
			queue2.pop();

		// or remove two items from queue1
		else {
			if (!queue1.empty())
				queue1.pop();
			else
				return 0;

			if (!queue1.empty())
				queue1.pop();
			else
				return 0;
		}
	}

	int aux[size], top = 0;

	// Empty all the queues into an auxiliary array.
	populateAux(aux, queue0, queue1, queue2, &top);

	// sort the array in non-increasing order
	sort(aux, aux + top, greater<int>());

	// print the result
	for (int i = 0; i < top; ++i)
		cout << aux[i] << " ";

	return top;
}
int main()
{

	int arr[] = { 8, 1, 7, 6, 0 };
	int size = sizeof(arr) / sizeof(arr[0]);

	if (findMaxMultupleOf3(arr, size) == 0)
		cout << "Not Possible";

	return 0;
}
