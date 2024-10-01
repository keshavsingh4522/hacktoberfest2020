
#include <iostream>
using namespace std;

int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

void countingSort(int array[], int size, int place) {
  const int max = 10;
  int output[size];
  int count[max];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

 
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;

  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];

 
  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

void radixsort(int array[], int size) {
  // Get maximum element
  int max = getMax(array, size);

  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}


void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}


int main() {
  int array[] = {121, 432, 564, 23, 1, 45, 788};
  int n = sizeof(array) / sizeof(array[0]);
  radixsort(array, n);
  printArray(array, n);
}
