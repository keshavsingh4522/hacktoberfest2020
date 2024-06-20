#include <iostream>
using namespace std;
/**
 * 
 *  Aman Upadhyay
 *  Amity University Kolkata
 * 
*/
int main()
{
    int n;
    cin >> n;

    if (( n % 2 != 0) || (6 <= n && n <= 20))
    {
        cout << "Weird";
    }
    else
    {
        cout << "Not Weird";
    }
    return 0;
}