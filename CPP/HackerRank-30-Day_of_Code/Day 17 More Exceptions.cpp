#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;
/**
 * 
 *  Aman Upadhyay
 *  Amity University Kolkata
 * 
*/
class MyException: public exception
{
    virtual const char* what() const throw()
    {
        return "n and p should be non-negative";
    }
}myExcept;

class Calculator
{
    public:
    Calculator(){}

    int power(int n, int p)
    {
        if (n < 0 || p < 0)
        {
            throw myExcept;
        }
        int pow = 1;
        for (int i = 0; i < p; i++)
        {
            pow *= n;
        }
        return pow;
    }
};

int main()
{
    Calculator myCalculator = Calculator();
    int T, n, p;
    cin >> T;

    while (T --> 0)
    {
        if (scanf("%d %d", &n, &p)==2)
        {
            try
            {
                int ans = myCalculator.power(n,p);
                cout << ans << endl;
            }
            catch(exception& e)
            {
                cout << e.what() << '\n';
            }
        }
    }
}