#include <iostream>
using namespace std;

int main()
{
     int Num, digit, check, reverse = 0;

     cout << "Enter a positive number: ";
     cin >> Num;

     check = Num;

    while(Num != 0)
    {
         digit = Num % 10;
         reverse = (reverse * 10) + digit;
         Num = Num / 10;
    }
    

     if (check == reverse)
         cout << " The number is a palindrome.";
     else
         cout << " The number is not a palindrome.";

    return 0;
}