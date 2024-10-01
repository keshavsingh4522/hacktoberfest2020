#include <iostream>
using namespace std;

bool is_prime(int n) {
    // Assumes that n is a positive natural number
    // We know 1 is not a prime number
    if (n == 1) {
        return false;
    }

    int i = 2;
    // This will loop from 2 to int(sqrt(x))
    while (i*i <= n) {
        // Check if i divides x without leaving a remainder
        if (n % i == 0) {
            // This means that n has a factor in between 2 and sqrt(n)
            // So it is not a prime number
            return false;
        }
        i += 1;
    }
    // If we did not find any factor in the above loop,
    // then n is a prime number
    return true;
}

int main() {
    for(int x=1; x<11; x++) {
        cout << x << ": " << (is_prime(x) ? "true" : "false") << endl;
    }
    cout << 1000000000 << ": " <<  (is_prime(1000000000) ? "true" : "false") << endl;
    // Output: 1000000000: false
    cout << 1000000007 << ": " <<  (is_prime(1000000007) ? "true" : "false") << endl;
    // Output: 1000000007: true
    return 0;
}
