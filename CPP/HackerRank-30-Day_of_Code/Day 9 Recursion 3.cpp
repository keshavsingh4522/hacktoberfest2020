#include <iostream>
using namespace std;
/**
 * 
 *  Aman Upadhyay
 *  Amity University Kolkata
 * 
*/
int factorial(int n)
{
    return ( n > 1 ) ? n * factorial ( n-1 ) : 1;
}

int main()
{
    int n; cin >> n;
    cout << factorial(n);
    return 0;
}