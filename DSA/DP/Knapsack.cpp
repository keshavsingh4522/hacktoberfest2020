/*Algorithm

> Create a two-dimensional array with n+1 rows and w+1 columns. A row number n denotes the set of items from 1 to i, and a column number w denotes the maximum carrying capacity of the bag.
> The numeric value at [i][j] denotes the total value of items up till i in a bag that can carry a maximum weight of j.
> At every coordinate [i][j] in the array, pick the maximum value that we can obtain without item i, or the maximum value that we can obtain with item i---whichever is larger.
> The maximum obtainable value by including item i is the sum of item i itself and the maximum value that can be obtained with the remaining capacity of the knapsack.
> Perform this step until you find the maximum value for the Wth row.
*/

//Program:

#include<stdio.h>
#include<conio.h>
#include<iostream>
 
using namespace std;
 
// A utility function that returns maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}
 
// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
    // Base Case
    if (n == 0 || W == 0)
        return 0;
 
    // If weight of the nth item is more than Knapsack capacity W, then
    // this item cannot be included in the optimal solution
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
 
    // Return the maximum of two cases: (1) nth item included (2) not included
    else
        return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
                knapSack(W, wt, val, n - 1));
}
 
// Driver program to test above function
int main()
{
    cout << "Enter the number of items in a Knapsack:";
    int n, W;
    cin >> n;
    int val[n], wt[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value and weight for item " << i << ":";
        cin >> val[i];
        cin >> wt[i];
    }
 
    //    int val[] = { 60, 100, 120 };
    //    int wt[] = { 10, 20, 30 };
    //    int W = 50;
    cout << "Enter the capacity of knapsack";
    cin >> W;
    cout << knapSack(W, wt, val, n);
 
    return 0;
}