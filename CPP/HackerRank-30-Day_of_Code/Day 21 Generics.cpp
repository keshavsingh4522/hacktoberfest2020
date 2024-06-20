#include <iostream>
#include <vector>
#include <string>
using namespace std;
/**
 * 
 *  Aman Upadhyay
 *  Amity University kolkata
 * 
*/
template<typename T>
void printArray (vector<T> array)
{
    for(T i: array)
    {
        cout << i << endl;
    }
}
int main()
{
    int n; cin >> n;
    vector<int> int_vector(n);
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        int_vector[i] = value;
    }
    cin >> n;
    vector<string> string_vector(n);
    for (int i = 0; i < n; i++)
    {
        string value;
        cin >> value;
        string_vector[i] = value;
    }
    printArray<int>(int_vector);
    printArray<string>(string_vector);

    return 0;
}