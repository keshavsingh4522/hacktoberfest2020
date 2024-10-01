//Overloading is creating more than one fx or class with the same name

#include <iostream>
using namespace std;

class complex
{
    int a, b;

public:
    complex()                                               //Default constructor
    {
        a = 0;
        b = 0;
    }

    complex(int x, int y)                                   //Parametrized constructors
    {
        a = x;
        b = y;
    }

    complex(int x)                                          //Parametrized constructors
    {
        a = x;
        b = 0;
    }

    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};
int main()
{
    complex c1(2, 3);
    c1.printNumber();

    complex c2(5);
    c2.printNumber();

    complex c3;
    c3.printNumber();
    return 0;
}
