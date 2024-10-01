#include <iostream>
using namespace std;

int main()
{
  int num1, num2, i, num, digit, sum;
// Enter lower limit 
  cin >> num1;
// Enter upper limit
  cin >> num2;

// Finding all armstrong numbers between the range
  for(i = num1; i <= num2; i++)
  {
        sum = 0;
        num = i;

        for(; num > 0; num /= 10)
        {
            digit = num % 10;
            sum = sum + digit * digit * digit;
        }

        if(sum == i)
        {
            cout << i << endl;
        }
  }

  return 0;
}
