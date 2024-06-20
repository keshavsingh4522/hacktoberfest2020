#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
/**
 * 
 *  Aman Upadhyay
 *  Amity University Kolkata
 * 
*/
class AdvancedArithmetic
{
    public:
          virtual int divisorSum(int n)=0;
};

class Calculator: public AdvancedArithmetic
{
    int divisorSum(int n)
    { int sum=0;

     for(int i=1;i<n;i++)
     {
         if (n%i==0)
         {
          sum+=i;
         }
     }
       return sum+n;
    }
};

int main()
{
    int n;
    cin >> n;

    AdvancedArithmetic *myCalculator = new Calculator();
    int sum = myCalculator ->divisorSum(n);

    cout << "I implemented: AdvancedArithmetic\n" << sum;
    return 0;
}