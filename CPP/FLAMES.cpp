// C++ program to implement FLAMES game
#include <bits/stdc++.h>
using namespace std;

// Function to find out the flames result
void flame(char* a, char* b)
{
	int i, j, k, l = 1, n, m, sc = 0, tc, rc = 0, fc = 5;
	char q[25], w[25], c;
	char f[] = "flames";

	strcpy(q, a);
	strcpy(w, b);
	n = strlen(a);
	m = strlen(b);
	tc = n + m;

	for (i = 0; i < n; i++)
	{
		c = a[i];
		for (j = 0; j < m; j++)
		{
			if (c == b[j])
			{
				a[i] = -1;
				b[j] = -1;
				sc = sc + 2;
				break;
			}
		}
	}

	rc = tc - sc;

	for (i = 0;; i++)
	{
		if (l == (rc))
		{
			for (k = i; f[k] != '\0'; k++)
			{
				f[k] = f[k + 1];
			}
			f[k + 1] = '\0';
			fc = fc - 1;
			i = i - 1;
			l = 0;
		}
		if (i == fc)
		{
			i = -1;
		}
		if (fc == 0)
		{
			break;
		}
		l++;
	}

	// Print the results
	if (f[0] == 'e')
		cout << q <<" is ENEMY to " << w;
	else if (f[0] == 'f')
		cout << q <<" is FRIEND to "<<w;
	else if (f[0] == 'm')
		cout << q <<" is going to MARRY "<<w;
	else if (f[0] == 'l')
		cout << q <<" is in LOVE with "<<w;
	else if (f[0] == 'a')
		cout << q <<" has more AFFECTION on "<<w;
	else
		cout << q << " and "<< w <<" are SISTERS/BROTHERS ";
}

// Driver code
int main()
{
	char a[] = "AJAY";
	char b[] = "PRIYA";

	flame(a, b);
}
