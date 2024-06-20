#include <iostream>
using namespace std;


void reverseArray(int arr[],int start,int end)
{

    while(start<end)
    {

        int temp= arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;

    }
}

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i];
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6};

    int n = sizeof(arr) / sizeof(arr[0]);

    // To print original array
    printArray(arr, n);

    // Function calling
    reverseArray(arr, 0, n-1);

    cout << "Reversed array is" << endl;

    // To print the Reversed array
    printArray(arr, n);

    return 0;








}



//to reverse string  cout << b.at(0) << a.substr(1) << ' ';
   // cout << a.at(0) << b.substr(1) << endl;






