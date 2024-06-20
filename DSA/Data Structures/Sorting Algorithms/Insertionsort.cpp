#include <bits/stdc++.h>
#include "random.h"
using namespace std;

void insertionSort(vector<int> &x)
{
    int n = x.size();
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j>0 && x[j] < x[j - 1])
        {
            swap(x[j],x[j--]);
        }
    }
}

int main()
{
    vector<int> v;
    populate(v, 10);
    print(v, "Unsorted");
    insertionSort(v);
    print(v, "Sorted  ");
    return 0;
}
