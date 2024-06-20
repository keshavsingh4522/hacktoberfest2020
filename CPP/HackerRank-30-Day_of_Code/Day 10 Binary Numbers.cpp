#include <bits/stdc++.h>
using namespace std;
/**
 * 
 *  Aman Upadhyay
 *  Amity University Kolkata
 * 
*/
int main()
{
    int n, count = 0, max = 0;
    cin >> n;

    while ( n )
    {
        if ( n & 1 )
        {
            count ++;
        }
        else
        {
            count = 0;
        }
        if ( max < count )
        {
            max = count;
        }
        n >>= 1;
    }
    cout <<  max;
    return 0;
}