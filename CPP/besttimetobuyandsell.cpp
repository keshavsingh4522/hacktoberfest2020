#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    
    int minPrice = prices[0];  // Initialize the minimum price to the first element
    int maxProfit = 0;         // Initialize maximum profit to 0

    // Iterate through the array
    for (int i = 1; i < prices.size(); i++) {
        // Update the minimum price if a lower price is found
        minPrice = min(minPrice, prices[i]);
        
        // Calculate the profit by selling on the current day and update maxProfit
        maxProfit = max(maxProfit, prices[i] - minPrice);
    }

    return maxProfit;
}

int main() {
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    vector<int> prices2 = {7, 6, 4, 3, 1};
    vector<int> prices3 = {1, 2, 3, 4, 5};

    cout << "Max profit for prices1: " << maxProfit(prices1) << endl;  // Output: 5
    cout << "Max profit for prices2: " << maxProfit(prices2) << endl;  // Output: 0
    cout << "Max profit for prices3: " << maxProfit(prices3) << endl;  // Output: 4

    return 0;
}
