#include <bits/stdc++.h>
#include "random.h"
using namespace std;

void bubbleSort(vector<int> &x)
{
    int n = x.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (x[j] > x[j + 1])
                swap(x[j], x[j + 1]);
        }
    }
}

int main()
{
    vector<int> v;
    // Insert 10 random values into the vector v
    populate(v, 10);
    print(v, "Unsorted");
    bubbleSort(v);
    print(v, "Sorted  ");

    return 0;
}
