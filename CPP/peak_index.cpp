#include<bits/stdc++.h>
using namespace std;

int peakindex(int arr[], int size)
{
int s = 0;
int e = size -1;

int mid = s  + (e - s)/2;
   
   while ( s < e)
     {
        if ( arr[mid] < arr [mid + 1])
        {
            s = mid + 1;
        }
        else 
        {
            e = mid;
        }
        mid = s  + (e - s)/2;
     }
     return s;
}

int main()
{
   int value[] = {10,15,100,25,90,81,77,55,45};
    cout << " Peak index of this array is " << peakindex(value, 9 );
}