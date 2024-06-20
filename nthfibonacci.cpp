#include <iostream>
int fib(int n)
{
    if(n==0 or n==1)
    return n;
    return fib(n-1)+fib(n-2);
}
using namespace std;

int main()
{
    int n;
    cin>>n;
    cout<<fib(n);
    return 0;
}
