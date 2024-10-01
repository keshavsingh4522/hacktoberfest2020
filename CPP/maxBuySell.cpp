#include <bits/stdc++.h>

using namespace std;

int maxBuySell(int arr[], int n) {
    int profit=0;
    for(int i=1;i<n;i++)
    if(arr[i]>arr[i-1])
    profit+=(arr[i]-arr[i-1]);
    
    return profit;
}

int main()
{
    int n;
    cout << "Enter the number of days: ";
    cin >> n;
    int arr[n];
    cout << "Enter the future stock values: " << endl;
    for(int i=0;i<n;i++) cin >> arr[i];
    
    cout << "Maximum money that one can make out is: " << maxBuySell(arr, n);

    return 0;
}
