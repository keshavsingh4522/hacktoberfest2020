
#include <iostream>

#include <cstring>

#include <cstdlib>

#define ll long long

using namespace std;

/* calculates (a * b) % c taking into account that a * b might overflow      */

ll mulmod(ll a, ll b, ll mod)

{

    ll x = 0,y = a % mod;

    while (b > 0)

    {

        if (b % 2 == 1)

        {    

            x = (x + y) % mod;

        }

        y = (y * 2) % mod;

        b /= 2;

    }

    return x % mod;

}

/* modular exponentiation     */

ll modulo(ll base, ll exponent, ll mod)

{

    ll x = 1;

    ll y = base;

    while (exponent > 0)

    {

        if (exponent % 2 == 1)

            x = (x * y) % mod;

        y = (y * y) % mod;

        exponent = exponent / 2;

    }

    return x % mod;

}

/* Miller-Rabin primality test, iteration signifies the accuracy     */

bool Miller(ll p,int iteration)

{

    if (p < 2)

    {

        return false;

    }

    if (p != 2 && p % 2==0)

    {

        return false;

    }

    ll s = p - 1;

    while (s % 2 == 0)

    {

        s /= 2;

    }

    for (int i = 0; i < iteration; i++)

    {

        ll a = rand() % (p - 1) + 1, temp = s;

        ll mod = modulo(a, temp, p);

        while (temp != p - 1 && mod != 1 && mod != p - 1)

        {

            mod = mulmod(mod, mod, p);

            temp *= 2;

        }

        if (mod != p - 1 && temp % 2 == 0)

        {

            return false;

        }

    }

    return true;

}

//Main

int main()

{

    int iteration = 5;

    ll num;

    cout<<"Enter integer to test primality: ";

    cin>>num;

    if (Miller(num, iteration))

        cout<<num<<" is prime"<<endl;

    else

        cout<<num<<" is not prime"<<endl;

    return 0;

}
