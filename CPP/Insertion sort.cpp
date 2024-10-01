//This is a program to display Insertion Sort
//In Insertion sort we insert the new element in a Sorted Array 
//In Array, we will have to shift the elment every time the element in consid is greater than the new element.

//The time complexity for Insertion an element in both Array is O(n)-max and O(1)-min.
//Insertion Sort is adoptive by nature as it takes O(n) time for sorted array.
//Further it is also stable at same time.
//Time Complexity for n elements : Max - O(n^2){reverse sorted} Min-O(n){sorted}
//No of Swaps : Max - O(n^2){reverse sorted} Min-O(1){sorted}

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int s,i,j,current;
    // Enter array from user
    cout<<"enter size of array :";        
    cin>>s;
    int arr[s];
    for(i=0;i<s;i++)
    {
        cin>>arr[i];
    }
    
    //Insertion sort algorithm
    for(i=1;i<s;i++)
    {
        current=arr[i];
        j=i-1;
        
        while(arr[j]>current&&j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        j++;
        arr[j]=current;
    }
    
    //Print the sorted array
    for(i=0;i<s;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
