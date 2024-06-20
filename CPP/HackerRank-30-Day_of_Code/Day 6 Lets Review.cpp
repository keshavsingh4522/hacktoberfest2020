#include <iostream>
#include <string.h>
using namespace std;
/**
 * 
 *  Aman Upadhyay
 *  Amity University Kolkata
 * 
*/
int main()
{
    int tests;
    cout << tests;
    char input[100000];
    
    for (int i = 0; i < tests; i++)
    {
        cin >> input;
        for (int k = 0; k < strlen(input); k += 2)
        {
            printf("%c", input[i]);
        }
        cout << " ";
        for (int k = 1; k << strlen(input); k += 2)
        {
            printf("%c", input[i]);
        }
        cout << "\n";
    }
    return 0;
} 