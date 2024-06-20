// Optimized bubble sort in C++

#include <iostream>
using namespace std;

void bubbleSort(int array[], int size) {
    for (int step = 0; step < size - 1; ++step) {
        // Run loops two times: one for walking throught the array
        // and the other for comparison
        int swapped = 0;
        for (int i = 0; i < size - step - 1; ++i) {
            // To sort in descending order, change > to < in this line.
            if (array[i] > array[i + 1]) {

                // Swap if greater is at the rear position
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1;
            }
        }

        // If there is not swapping in the last swap, then the array is already sorted.
        if (swapped == 0)
            break;
    }
}

// Function to print an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "  " << array[i];
    }
    cout << "\n";
}

// Driver code
int main() {
    int data[] = {-2, 45, 0, 11, -9};
    int size = sizeof(data) / sizeof(data[0]);
    bubbleSort(data, size);
    cout << "Sorted Array in Ascending Order:\n";
    printArray(data, size);
}
/*
 * Number of comparisons: (n - 1) + (n - 2) + (n - 3) +.....+ 1 = n(n - 1) / 2 nearly equals to n^2
 * Complexity: O(n^2)
 * Worst Case Complexity:O(n^2)
If we want to sort in ascending order and the array is in descending order then, the worst case occurs.

Best Case Complexity:O(n)
If the array is already sorted, then there is no need for sorting.

Average Case Complexity:O(n^2)
It occurs when the elements of the array are in jumbled order (neither ascending nor descending).

 Space complexity is O(1) because an extra variable temp is used for swapping.

In the optimized algorithm, the variable swapped adds to the space complexity thus, making it O(2).
 */