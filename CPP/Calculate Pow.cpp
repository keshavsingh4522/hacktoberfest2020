#include <iostream>

using namespace std;

int main() {
    int b, x, i;
    long long r = 1;

    // b - denotes base number
    // x - denotes exponent number
    // r - denotes result value
    
    cout << "-----Enter the input of base number-----\n";
    cin >> b;

    cout << "\n-----Enter the input of exponent number-----\n";
    cin >> x;

    for (i = x; i > 0; i--) {
        r *= b;
    }

    cout << "\nThe calculation of the power of N number is " << b << "^" << x << " = " << r << "\n";
    
    return 0;
}
