#################################################################

## Description

Function Template :

template <class type> ret-type func-name(parameter list)

{
// body of function
}

Class Template :

template <class type> class class-name

{
.
.
.
}

Output :+1: 

Enter two integers:
8 3
8 is larger.

Enter two floating-point numbers:
1.2
5.6
5.6 is larger.

Enter two characters:
f
i
I have a larger ASCII value. 


#################################################################

#include <iostream>
using namespace std;

template <class T>
T Large(T n1, T n2)
{
        return (n1 > n2) ? n1 : n2;
}

int main()
{
        int i1, i2;
        float f1, f2;
        char c1, c2;

        cout << "Enter two integers:\n";
        cin >> i1 >> i2;
        cout << Large(i1, i2) <<" is larger." << endl;

        cout << "\nEnter two floating-point numbers:\n";
        cin >> f1 >> f2;
        cout << Large(f1, f2) <<" is larger." << endl;

        cout << "\nEnter two characters:\n";
        cin >> c1 >> c2;
        cout << Large(c1, c2) << " has larger ASCII value.";

        return 0;
}
