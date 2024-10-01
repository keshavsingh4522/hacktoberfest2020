/* Algorithm:
>>> Build a max heap
>>> Keep extracting maximum element,
    until only one element left in the max heap.
*/

#include <iostream>
using namespace std;

void Build_max_heap(int*, int);
void max_heapify(int*, int, int);
void max_heap_sort(int*, int);
void swap(int*, int*);
void PRINT(int*, int);

int main()
{
    int arr[] = {5, 16, 22, 45, 2, 10, 18, 30, 50, 12, 1};
    int len = 11;
    cout<<"Actual array: ";
    PRINT(arr, len);
    cout<<endl;

    Build_max_heap(arr, len);
    cout<<"Max Heap: ";
    PRINT(arr, len);

    max_heap_sort(arr, len);
    cout<<"\nSorted Array: ";
    PRINT(arr, len);
    cout<<endl;
}

void Build_max_heap(int* arr, int len)
{
    for(int i=len/2; i>=0; i--)
        max_heapify(arr, len, i);
}

void max_heap_sort(int* arr, int len)
{
    while(len>1)
    {
        /*Swap the last element of heap with first element.
        And decrement the size of heap by 1.
        */
        swap(arr, arr+--len);
        max_heapify(arr, len, 0);
        cout<<"Max Heap: ";
        PRINT(arr, len);
    }
}

void max_heapify(int* arr, int len, int i)
{
    //index of left and right child
    int left = i*2+1, right = i*2+2;
    // Index of largest element
    int max_ind = i;
    // If left child greater than element at max_ind
    if(left < len && arr[max_ind] < arr[left])
        max_ind = left;
    // If right child greater than element at max_ind
    if(right < len && arr[max_ind] < arr[right])
        max_ind = right;

    /*If root is the max element return
    Else swap the max element with root, and apply the max_heapify in respective sub-heap
    */
    if(max_ind == i)
        return;

    swap(arr+max_ind, arr+i);
    max_heapify(arr, len, max_ind);
}

void swap(int*a, int*b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void PRINT(int *arr, int len)
{
    for(int i=0; i<len; i++)
        printf("%2d ", arr[i]);

    cout<<endl;
}
