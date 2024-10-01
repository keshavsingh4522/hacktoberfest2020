#include <iostream>
#include <ctime>
using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

//Sort the elements in increasing order
void bubble_sort(int a[], int n)
{

    for (int times = 1; times <= n - 1; times++)
    {
        //repeated swapping
        for (int j = 0; j <= n - times - 1; j++)
        {
            if (compare(a[j], a[j + 1]))
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

int main()
{
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);

    bubble_sort(arr, n);

    return 0;
}