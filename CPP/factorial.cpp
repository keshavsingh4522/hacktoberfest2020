
#include <iostream>

using namespace std;

int multiply(int x, int a[], int size)
{
    int c = 0, i, p;

    for (i = 0; i < size; ++i)
    {
        p = a[i] * x + c;
        a[i] = p % 10;
        c = p / 10;
    }
    while (c != 0)
    {
        a[size] = c % 10;
        carry = c / 10;
        size++;
    }
    return size;
}

int main()
{
    int n, a[1000], i, size = 1;
    a[0] = 1;

    cout << "Enter any large number:";
    cin >> n;

    for (i = 2; i <= n; ++i)
    {
        size = multiply(i, a, size);
    }

    for (i = size - 1; i >= 0; --i)
    {
        cout << a[i];
    }

    return 0;
}
