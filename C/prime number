#include <iostream>
using namespace std;

bool checkPrimeNumber(int);

int main() {
    int n;

    cout << "Enter a positive  integer: ";
    cin >> n;

    if (checkPrimeNumber(n))
        cout << n << " is a prime number.";
    else
        cout << n << " is not a prime number.";
    return 0;
}

bool checkPrimeNumber(int n) {
    bool isPrime = true;

    // 0 and 1 are not prime numbers
    if (n == 0 || n == 1) {
        isPrime = false;
    }
    else {
        for (int i = 2; i <= n / 2; ++i) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
    }
    return isPrime;
}
