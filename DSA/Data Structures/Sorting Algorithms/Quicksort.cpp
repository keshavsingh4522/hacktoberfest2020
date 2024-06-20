#include <bits/stdc++.h>
#include "random.h"
using namespace std;

int partition(vector<int> &x, int low, int high)
{
    int pivot = x[low], i = low + 1, j = high;

    do
    {
        while (x[i] <= pivot)
            i++;

        while (x[j] > pivot)
            j--;

        if (i < j)
            swap(x[i], x[j]);
    } while (i < j);

    swap(x[low], x[j]);
    return j;
}
void quickSort(vector<int> &x, int low, int high)
{
    if (low < high)
    {
        int pI = partition(x, low, high);
        quickSort(x, low, pI - 1);
        quickSort(x, pI + 1, high);
    }
}

int main()
{
    vector<int> v;
    populate(v,10);
    print(v,"Unsorted");
    quickSort(v,0,v.size()-1);
    print(v,"Sorted  ");

    return 0;
}
