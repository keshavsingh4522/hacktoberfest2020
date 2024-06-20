#include <bits/stdc++.h>
#include "random.h"
using namespace std;

void selectionSort(vector<int> &x)
{
    int n = x.size();

    for (int i = 0; i < n-1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (x[i] > x[j])
                swap(x[i], x[j]);
        }
    }
    
}

int main()
{
    vector<int> v;
    populate(v,10);
    print(v,"Unsorted");
    selectionSort(v);
    print(v,"Sorted  ");

    return 0;
}
