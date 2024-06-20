#include <iostream>
#include <stack>
#include <cmath>

using namespace std;



float scanNum (char ch)
{
    int value;
    value = ch;
    return float (value - '0');
}


int isOperator (char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    return -1;
}


int isOperand (char ch)
{
    if (ch >= '0' && ch <= '9')
        return 1;
    return -1;
}

float operation (int a , int b , char op)
{

    if (op == '+')
        return b + a;
    else if (op == '-')
        return b - a;
    else if (op == '*')
        return b * a;
    else if (op == '/')
        return b / a;
    else if (op == '^')
        return pow (b , a);
    else
        return INT_MIN;
}

//function to Solve Postfix Expression
float postfixEvaluation (string postfix)
{
    int a , b;
    stack<float> stk;
    string::iterator it;
    for (it = postfix.begin (); it != postfix.end (); it++) {
        if (isOperator (*it) != -1) {
            a = stk.top ();
            stk.pop ();
            b = stk.top ();
            stk.pop ();
            stk.push (operation (a , b , *it));
        }
        else if (isOperand (*it) > 0) {
            stk.push (scanNum (*it));
        }
    }
    return stk.top ();
}

int main ()
{
    string postfix;
    cout << "Enter postfix expression :- ";/* Enter postfix expression like (34+) */
    cin >> postfix;
    cout << "After evaluation :- " << postfixEvaluation (postfix);
}


/*  Sample Input:
    34+

    Sample Output:
    7
*/

/* Explanation : 34+ in postfix is 3+4 in infix expression which gives 7 as output */

/* Time Complexity :-  O(string size)
