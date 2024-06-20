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

    for (int i = 1; i <= 10; i++)
    {
        int res = n*i;
        cout << n << " x " << i << " = " << res << "\n";
    }
    return 0;
}