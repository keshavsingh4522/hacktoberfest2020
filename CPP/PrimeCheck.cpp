/* 
------------------------------------------------------------------------------------------------
USERNAME: RASESH2005
DESCRIPTION: THIS PROGRAM CHECKS IF A NUMBER IS PRIME OR NOT
DATE: 1/10/2021
------------------------------------------------------------------------------------------------
*/
#include <bits/stdc++.h>

using namespace std;

//SNIPPET
bool isPrime(int n)
{
    for (int i = 2; i <= int(sqrt(n) + 1); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    //APPLICATION
    bool result = isPrime(24498757); //calling function
    cout << result << endl;
    cout << (result ? "Prime" : "Not A Prime") << endl;
    return 0;
}
