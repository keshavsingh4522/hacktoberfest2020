#include <bits/stdc++.h>
using namespace std;
class Test
{
public:
    int a, b;
    Test() {}
    Test(int c, int d)
    {
        a = c;
        b = d;
    }
    friend Test operator-(Test, Test);
    // member function
    Test operator+(Test t2)
    {
        cout<<"Addition using member function"<<endl;
        Test t3;
        t3.a = a + t2.a;
        t3.b = b + t2.b;
        return t3;
    }
    void dis()
    {
        cout << "a=" << a << '\t' << "b=" << b << endl;
    }
};
// friend function
Test operator-(Test t1, Test t2)
{
    cout<<"Subtraction using friend function"<<endl;
    Test t3;
    t3.a = t1.a - t2.a;
    t3.b = t1.b - t2.b;
    return t3;
}
int main()
{
    Test s1(2, 7), s2(5, 9), s3, s4;
    cout<<"Original Value\n";
    s1.dis();
    s2.dis();
    s3 = s1 - s2;
    s3.dis();

    s4 = s1 + s2;
    s4.dis();
}