#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

int maxProfit(const vector<int>& prices) {
    int min_price = INT_MAX; // Initialize the minimum price to a large value
    int max_profit = 0;      // Initialize max profit to 0

    // Iterate through each price
    for (int price : prices) {
        // Update the minimum price encountered so far
        if (price < min_price) {
            min_price = price;
        }
        // Calculate the profit if we sell today and update max profit
        int profit = price - min_price;
        if (profit > max_profit) {
            max_profit = profit;
        }
    }

    return max_profit;
}

int main() {
    int n;
    // Take input for the number of days
    cout << "Enter the number of days: ";
    cin >> n;

    vector<int> prices(n);

    // Take input for stock prices
    cout << "Enter the stock prices for each day: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    // Find and print the maximum profit
    int result = maxProfit(prices);
    cout << "The maximum profit is: " << result << endl;

    return 0;
}
