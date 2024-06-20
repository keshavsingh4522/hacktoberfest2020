#include <bits/stdc++.h>
#include "random.h"
using namespace std;

void merge(vector<int> &x, int low, int mid, int high)
{
    vector<int> y;
    int i = low, j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (x[i] < x[j])
        {
            y.push_back(x[i]);
            i++;
        }
        else if (x[j] < x[i])
        {
            y.push_back(x[j]);
            j++;
        }
        else
        {
            y.push_back(x[i]);
            y.push_back(x[j]);
            i++, j++;
        }
    }
    while (i <= mid)
    {
        y.push_back(x[i]);
        i++;
    }
    while (j <= high)
    {
        y.push_back(x[j]);
        j++;
    }
    int counter = 0;
    for (int i = low; i <= high; i++)
        x[i] = y[counter++];
}

void mergeSort(vector<int> &x, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(x, low, mid);
        mergeSort(x, mid + 1, high);
        merge(x, low, mid, high);
    }
}

int main()
{
    vector<int> v;
    populate(v,10);
    print(v,"Unsorted");
    mergeSort(v,0,v.size()-1);
    print(v,"Sorted  ");
    return 0;
}
