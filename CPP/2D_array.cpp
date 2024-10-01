#include <bits/stdc++.h>
using namespace std;

bool  ispresent(int arr[][4], int target, int n, int m)
{
      for(int i =0; i <3; i++)
    {
        for(int j=0; j< 4; j++)
        {
            if(arr[i][j] == target)
            {
                return 1;
            }
        }
    }
    return 0;
} 

void printSum (int arr[][4],int n, int m )
{
      for(int i =0; i <3; i++)
    {
        int sum = 0;
        for(int j=0; j< 4; j++)
        {
            sum += arr[i][j];
        }
        cout << sum << " ";
    }
    cout << endl;
}

int largestRowSum(int arr[][4],int n, int m)
{
    int maxi = INT_MIN;
    int iIndex = -1;
    for(int i=0; i<3; i++)
    {
        int sum = 0;
    for(int m =0; m<4; m++)
    {
     sum += arr[n][m];
    }
      if(sum > maxi)
      {
        maxi = sum;
        iIndex = n;
      }
    }
    cout << " The maximum sum is" << maxi << endl;
  return iIndex;
}

int main()
{
      int arr[3][4];
   cout << " Enter the numbers you want:";
    for(int i =0; i <3; i++)
    {
        for(int j=0; j< 4; j++)
        {
            cin >> arr[i][j];
        }
    }

     for(int i =0; i <3; i++)
    {
        for(int j=0; j< 4; j++)
        {
            cout <<  arr[i] [j] <<" ";
        }
        cout << endl;
    }

    cout << " Enter the element you want to search: ";
    int target;
    cin >> target;

    if(ispresent(arr, target, 3,4))
    {
        cout << " Element found.." << endl;
    }
    else{
        cout << " Not found !!";
    }
   cout << " Sum of the row is " << " ";
   printSum( arr, 3,4);

   cout << " Max row is at index" <<largestRowSum(arr,3,4) << endl;
    return 0;
}
