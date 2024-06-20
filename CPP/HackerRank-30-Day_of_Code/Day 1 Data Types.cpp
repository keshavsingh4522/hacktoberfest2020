#include <iostream>
#include <string.h>
#include <limits>
#include <iomanip>
using namespace std;
/**
 *  
 *  Aman Upadhyay
 *  Amity University Kolkata
 * 
*/
int main()
{
    int i = 4, num;
    double d = 4.0, dnum;
    string s = "HackerRank ", snum;

    cin >> num >> dnum;
    getline(cin >> ws, snum);

    cout << i + num << endl;
    cout << fixed << setprecision(1) << d + dnum << endl;
    cout << s + snum << endl;

    return 0;
}