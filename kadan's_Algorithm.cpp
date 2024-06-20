#include <iostream>
#include <vector>

using namespace std;

int kadanes(vector<int>& numbers) {
    int maximumSum = INT_MIN;
    int currentSum = 0;

    for (int i = 0; i < numbers.size(); i++) {
        currentSum = currentSum + numbers[i];
        if (currentSum < 0) {
            currentSum = 0;
        }
        maximumSum = max(currentSum, maximumSum);
    }
    return maximumSum;
}

int main() {
    vector<int> numbers;
    numbers.push_back(-2);
    numbers.push_back(-3);
    numbers.push_back(4);
    numbers.push_back(-1);
    numbers.push_back(-2);
    numbers.push_back(1);
    numbers.push_back(5);
    numbers.push_back(-3);

    int maxSum = kadanes(numbers);
    cout << "Maximum Sum of Sub-Array is : " << maxSum << endl;

    return 0;
}
