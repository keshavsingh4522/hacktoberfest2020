#include<iostream>
#include<conio.h>



class Calculator
{
    public :
        int No1,No2,Ans;              // Data Members Characteristics or class variable

        Calculator();                 // Default Constructor of our Class  // only Declaration

        Calculator(int N1, int N2);   // Parameterized Constructor of our Class // Only Declaration

        void Add();                   // Member Function Add or Behaviors Declaration

        void Sub();                   // Member Function Sub or Behaviors Declaration

        ~Calculator();                // Destructor of our Class // Only Declaration
};

Calculator :: Calculator()                                                // Default Constructor Definition Outside class
{
     cout << endl << "\n Inside Default Constructor!!!" << endl;

     No1 = No2 = Ans = 0;
}

Calculator :: Calculator(int N1, int N2)                                   // Parameterized Constructor Definition Outside Class
{
     cout << endl << "\n Inside Parameterized Constructor!!!" << endl;

     No1 = N1;
     No2 = N2;
     Ans = 0;
}

void Calculator :: Add()                                                   // Member function or Behaviors Definition Outside class
{
     Ans = No1 + No2;
}

void Calculator :: Sub()                                                    // Member Function or Behaviors Definition Outside Class
{
      Ans = No1 - No2;
}

Calculator :: ~Calculator()
{
        cout << endl << "Inside Destructor of Our Calculator Class!!!" << endl;
}

int main()
{
        Calculator obj1;                                                      // Obj1 is an Object Created Using Default Constructor of our Class

        obj1.No1 = 10;
        obj1.No2 = 20;

        obj1.Add();

        cout << endl << "Addition is = " << obj1.Ans << endl;

        _getch();

        Calculator Obj2(100,55);                                               // Obj2 is an Object Created Using Default Constructor Of Our Class

        obj2.Sub();

        cout << endl << "Subtraction is = " << obj2.Ans << endl;

        _getch();
        return 0;
}
