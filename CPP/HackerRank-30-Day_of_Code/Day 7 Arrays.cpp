#include <iostream>
using namespace std;
/**
 * 
 *  Aman Upadhyay
 *  Amity University Kolkata
 * 
*/
int main()
{
    int arr[100000] , size, i, j, temp;
    cin >> size;

    for ( i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    j = i - 1; 
    i = 0;

    while ( i < j)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++; j--;
    }

    for ( i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}