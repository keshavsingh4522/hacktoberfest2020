#include <iostream>
#include <map>
using namespace std;
/**
 * 
 *  Aman Upadhyay
 *  Amity University Kolkata
 * 
*/
int main()
{
    std :: map<string, string> phoneBook;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string name, phone;
        cin >> name >> phone;
        phoneBook[name] = phone;
    }
    std :: map<string, string> :: iterator it;
    string query;

    while (cin >> query)
    {
        it = phoneBook.find(query);

        if ( it != phoneBook.end() )
        {
            cout << it -> first << "=" << it -> second << '\n';
        }
        else
        {
            cout << "Not found" << '\n';
        }
        
    }
    return 0;
}