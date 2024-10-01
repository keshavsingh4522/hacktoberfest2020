#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Implement various sorting algorithms
void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int partition_index = i + 1;
        quicksort(arr, low, partition_index - 1);
        quicksort(arr, partition_index + 1, high);
    }
}

void mergesort(vector<int>& arr) {
    if (arr.size() <= 1) {
        return;
    }
    int mid = arr.size() / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());
    mergesort(left);
    mergesort(right);
    merge(left.begin(), left.end(), right.begin(), right.end(), arr.begin());
}

void bubblesort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 3, 6};
    
    // Choose a sorting algorithm
    //quicksort(arr, 0, arr.size() - 1);
    //mergesort(arr);
    //bubblesort(arr);
    
    // Print the sorted array
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
