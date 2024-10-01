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
    friend Test operator--(Test);
    // member function
    void operator++(int)
    {
        cout<<"Post increment"<<endl;
        a++;
        b++;
    }
    void dis()
    {
        cout << "a=" << a << '\t' << "b=" << b << endl;
    }
};
// friend function
Test operator--(Test t2)
{
    cout<<"Pre decrement"<<endl;
    t2.a--;
    t2.b--;
    return t2;
}
int main()
{
    Test s1(22, 17), s2(5, 9), s3, s4;
    cout<<"Original Value\n";
    s2.dis();
    s3 = --s2;
    s3.dis();

    cout<<"Original Value\n";
    s1.dis();
    s1++;
    s1.dis();
}