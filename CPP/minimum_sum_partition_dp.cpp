#include <bits/stdc++.h>
using namespace std;

void subsets(int arr[], int n, int sum, vector<vector<int>> &t)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
                t[i][j] = 1;
            else if (i == 0)
                t[i][j] = 0;

            else if (arr[i - 1] > j)
            {
                t[i][j] = t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j] || t[i - 1][j - arr[i - 1]];
            }
        }
    }
}
int minDifference(int arr[], int n)
{
    // Your code goes here

    int range = 0;
    for (int i = 0; i < n; i++)
    {
        range += arr[i];
    }
    vector<vector<int>> t(n + 1, vector<int>(range + 1));
    subsets(arr, n, range, t);

    vector<int> ans;
    for (int i = 0; i < (range) / 2 + 1; i++)
    {
        if (t[n][i] == 1)
            ans.push_back(i);
    }

    int mn = INT_MAX;

    for (int i = 0; i < ans.size(); i++)
    {
        mn = min(mn, range - 2 * ans[i]);
    }

    return mn;
}

int main()
{
    int arr[]={1,6,11,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<minDifference(arr,n);
    return 0;
}