#include <iostream>
#include <string>
using namespace std;
/**
 * 
 *  Aman Upadhyay
 *  Amity University Kolkata
 * 
*/
int main()
{
    string num;
    cin >> num;

    int i;
    try
    {
        i = stoi(num);
        cout << num;
    }
    catch( exception e)
    {
        cout << "Bad String";
        return 0;
    }
    return 0;
}
