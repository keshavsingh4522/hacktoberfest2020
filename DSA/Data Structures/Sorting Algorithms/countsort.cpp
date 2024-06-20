#include <bits/stdc++.h>
#include "random.h"
using namespace std;

void countSort(vector<int> &x)
{
    int n = x.size();
    vector<int> output(n);
    int max_elem = *max_element(x.begin(), x.end());
    vector<int> count(max_elem + 1, 0);

    for (int i = 0; i < n; i++)
        count[x[i]]++;

    for (int i = 1; i < count.size(); i++)
        count[i] = count[i - 1] + count[i];

    for (int i = 0; i < x.size(); i++)
    {
        output[count[x[i]] - 1] = x[i];
        count[x[i]]--;
    }

    for (int i = 0; i < n; ++i)
    {
        x[i] = output[i];
    }
}
int main()
{
    vector<int> v;
    populate(v, 10);
    print(v, "Unsorted");
    countSort(v);
    print(v, "Sorted  ");

    return 0;
}
