#include <iostream>
using namespace std;

class complex;

class calculator
{
public:
    int add(int a, int b)
    {
        return a + b;
    }
    int sumcomplex(complex x, complex y);
};

class complex
{
private:
    int a, b;
    friend int calculator ::sumcomplex(complex, complex);

public:
    void setnum(int x, int y)
    {
        a = x;
        b = y;
    }
    void print()
    {
        cout << "The given vector is: " << a << " + " << b << +"i";
    }
};

int calculator ::sumcomplex(complex x, complex y)
{
    return x.a + y.a;
}

int main()
{
    complex i, j;
    i.setnum(2, 3);
    j.setnum(3, 6);

    calculator calc;
    cout << "The sum of complex numbers is " << calc.sumcomplex(i, j) << endl;

    return 0;
}
