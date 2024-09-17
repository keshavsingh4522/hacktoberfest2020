#include<iostream>

using namespace std;

void swap(int * p, int * q){
  int temp = * p;
  * p = * q;
  * q = temp;
}

void array_in_wave(int array[], int n){
  sort(array, array + n);
  for (int i = 0; i < n - 1; i += 2)
    swap( & array[i], & array[i + 1]);
}

int main(){
  int array[100], n, i;
  cout << "Enter number of elements: ";
  cin >> n;
  cout << "\nEnter elements: ";

  for (i = 0; i < n; i++)
    cin >> array[i];

  cout << "Original array: ";

  for (int i = 0; i < n; i++)
    cout << array[i] << " ";

  array_in_wave(array, n);

  cout << "\nWave form of the array is: ";

  for (int i = 0; i < n; i++)
    cout << array[i] << " ";

  return 0;
}
