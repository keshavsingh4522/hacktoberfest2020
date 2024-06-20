/*
problem : print all the prime numbers within a given number
output :

Enter the number : 20
All the prime factors  : 2 3 5 7 11 13 17 19 

*/
#include <iostream>
#include <limits.h>
using namespace std;

void sieve(int n)
{
	if (n <= 1)
		return;

	bool isPrime[n + 1];

	fill(isPrime, isPrime + n + 1, true);

	for (int i = 2; i * i <= n; i++)
	{
		if (isPrime[i])
		{
			for (int j = 2 * i; j <= n; j = j + i)
			{
				isPrime[j] = false;
			}
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (isPrime[i])
			cout << i << " ";
	}
}
int main()
{

	int n;
	cout << "Enter the number : ";
	cin >> n;
	cout << "All the prime factors  : ";
	sieve(n);
}
