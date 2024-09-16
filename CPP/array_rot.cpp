/*Divide the array in different sets 
where number of sets is equal to GCD of n and d 
and move the elements within sets. */
#include <iostream>
using namespace std;

int gcdFunc(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcdFunc(b, a % b);
}

void leftRotate(int arr[], int d, int n)
{
    d = d % n;
    int gcdVal = gcdFunc(d, n);
    for (int i = 0; i < gcdVal; i++)
    {
        int temp = arr[i];
        int j = i;

        while (1)
        {
            int k = j + d;
            if (k >= n)
                k = k - n;
            if (k == i)
                break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    leftRotate(arr, 2, n);
    printArray(arr, n);

    return 0;
}