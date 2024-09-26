#include <iostream>
using namespace std;

int array_for_BS = {1, 5, 8, 9 , 7, 6, 7 , 4, 2, 1, 0};

int binary_search_algorithm(int array[], int num, int beg, int end) {
  
	/*Loop until beginning matches with/is lesser than end*/
  while (beg <= end) 
  {
    int mid = beg + (end - beg) / 2;

    if (array[mid] == num)
      return mid;

    if (array[mid] < num)
      beg = mid + 1;

    else
      end = mid - 1;
  }
  /*We reach here only if element is not found in array, return -1 then*/
  return -1;
}

int main()
{
 int size = sizeof(array_for_BS)/sizeof(array_for_BS[0]);
  
  /*Sorting the array before we begin search*/
  sort(array_for_BS, array_for_BS + size);
  
  int result = binary_search_algorithm(array_for_BS, 4, 0, size - 1);
  if (result == -1)
    printf("Element not found in array");
  else
    printf("Element is found in the array, at position %d", result);
  
}

