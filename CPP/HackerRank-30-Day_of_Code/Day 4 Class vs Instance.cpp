#include <iostream>
using namespace std;
/**
 * 
 *  Aman Upadhyay
 *  Amity University Kolkata
 * 
*/
class Person
{
    public:
          int age;
          Person(int inititalAge);
          void amOld();
          void yearPassed();
};

Person::Person(int inititalAge)
{
    if (inititalAge < 0)
    {
        cout << "Age is not valid, setting age to 0." << endl;
        this -> age = 0;
    }
    else
    {
        this -> age = inititalAge;
    } 
}

void Person:: amOld()
{
    if (age >= 18)
    {
        cout << "You are old." << endl;
    }
    else if (age >= 13)
    {
        cout << "You are a teenager." << endl;
    }
    else
    {
        cout << "You are young." << endl;
    }
}

void Person :: yearPassed()
{
    this -> age++;
}

int main()
{
    int t, age;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> age;
        Person p(age);
        p.amOld();

        for (int j = 0; j < 3; j++)
        {
            p.yearPassed();
        }
        p.amOld();
        cout << "\n";
    }
    return 0;
}