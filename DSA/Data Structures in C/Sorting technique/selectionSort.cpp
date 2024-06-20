#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the size of the array";
    cin>>n;
    int arr[n];
    cout<<"enter the element of the array";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                int temp;
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
/*
 * Worst Case Complexity: O(n2)
If we want to sort in ascending order and the array is in descending order then, the worst case occurs.
Best Case Complexity: O(n2)
It occurs when the array is already sorted
Average Case Complexity: O(n2)
It occurs when the elements of the array are in jumbled order (neither ascending nor descending).
 Space complexity is O(1) because an extra variable temp is used.
 */