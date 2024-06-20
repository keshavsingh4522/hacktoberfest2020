#include <bits/stdc++.h>
using namespace std;
/**
 * 
 *  Aman Upadhyay
 *  Amity University Kolkata
 * 
*/
int main()
{
    vector < vector<int> > array( 6, vector<int>(6));

    for (int j = 0; j < 6; j++)
    {
        for (int i = 0; i < 6; i++)
        {
            cin >> array[j][i];
        }
    }
    int hoursum, maxsum = -64;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            hoursum = array[j+1][i+1];

            for (int k = 0; k < 3; k++)
            {
                hoursum = hoursum + array[j] [i+k] + array[j+2] [i+k];
            }
            if (hoursum > maxsum)
            {
                maxsum = hoursum;
            }
            
        }
        
    }
    cout << maxsum;
    return 0;
}