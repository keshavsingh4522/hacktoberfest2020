// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function that returns true if the string
// is made up of two alternating characters
bool isTwoAlter(string s)
{

	// Check if ith character matches
	// with the character at index (i + 2)
	for (int i = 0; i < s.length() - 2; i++) {
		if (s[i] != s[i + 2]) {
			return false;
		}
	}

	// If string consists of a single
	// character repeating itself
	if (s[0] == s[1])
		return false;

	return true;
}

// Driver code
int main()
{
	string str = "ABAB";

	if (isTwoAlter(str))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
