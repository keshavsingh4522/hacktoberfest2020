/*
Author: Siddhant Pandy
Program: Graphical representation of Sorting in command line
Topic: Bubble Sort
*/

#include<iostream>
#include<vector>
#include <time.h> 
using namespace std;

void swap(int *xp, int *yp)
{
	int temp=*xp;
	*xp=*yp;
	*yp=temp;
}

void delay(int number_of_seconds) 
{ 
    int milli_seconds = 1000 * number_of_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds) 
        ; 
} 

void display(vector <int> arr)
{
	for(int x=0;x<arr.size();x++)
	{
		cout<<"|"<<x<<"|";
		for(int y=0;y<arr[x];y++)
		{
			cout<<"-";
		}
		cout<<arr[x]<<endl;
	}
	cout<<endl<<endl;
delay(2);		
}

vector<int> bubbleSort(vector<int> arr)
{
	for(int x=0;x<arr.size()-1;x++)
	{
		for(int y=0;y<arr.size()-x-1;y++)
		{
			if(arr[y]>arr[y+1] )
			{
				swap(arr[y+1],arr[y]);
				display(arr);
			}
		}
	}
	
	return arr;
}

int main()
{
	int arr[] = {10,3,6,9,1,5,2,4,8,7};
	
	vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
	vec= bubbleSort(vec);
	display(vec);
  
}
