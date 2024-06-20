#include <bits/stdc++.h>
#include "random.h"
using namespace std;

void impselSort(vector<int> &x)
{
    int n = x.size();
    int i, j;
    for (i = 0, j = n - 1; i < j; i++, j--)
    {
        int minimum = x[i], maximum = x[j], min_index = i, max_index = j;
        for (int k = i; k <= j; k++)
        {
            if (x[k] < minimum)
            {
                minimum = x[k];
                min_index = k;
            }
            if (x[k] > maximum)
            {
                maximum = x[k];
                max_index = k;
            }
        }
        swap(x[i], x[min_index]);
        if (x[min_index] == maximum)
            swap(x[j], x[min_index]);
        else
            swap(x[j], x[max_index]);
    }
}

int main()
{
    vector<int> v;
    populate(v, 10);
    print(v, "Unsorted");
    impselSort(v);
    print(v, "Sorted  ");
    return 0;
}
