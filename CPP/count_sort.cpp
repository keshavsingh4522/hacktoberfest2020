#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define RANGE 255

// The main function that sort the given string arr[] in alphabetical order
void countSort(char arr[])
{
	char output[strlen(arr)];

	int count[RANGE + 1], i;
	memset(count, 0, sizeof(count));

	// Store count of each character
	for (i = 0; arr[i]; ++i)
		++count[arr[i]];

	for (i = 1; i <= RANGE; ++i)
		count[i] += count[i - 1];

	for (i = 0; arr[i]; ++i) {
		output[count[arr[i]] - 1] = arr[i];
		--count[arr[i]];
	}

	/*
	for (i = sizeof(arr)-1; i>=0; --i)
	{
		output[count[arr[i]]-1] = arr[i];
		--count[arr[i]];
	}
	
	*/

	for (i = 0; arr[i]; ++i)
		arr[i] = output[i];
}

int main()
{
    //an example
	char arr[] = "Imadethispullrequest";

	countSort(arr);

	cout << "Sorted character array is " << arr;
	return 0;
}

// This code is contributed by rathbhupendra
