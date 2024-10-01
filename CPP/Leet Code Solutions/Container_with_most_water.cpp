#include <bits/stdc++.h>
using namespace std;

//container with most water

    int maxArea(int height[], int n) {
        
        
        int maxWater = 0;
        
        int i = 0, j = n - 1;
        
        while(i < j){
            //int currMax = 0;
            int x = min(height[i], height[j]);
            int currMax = x * (j-i);
            maxWater = max(maxWater, currMax);
            
            if(height[i] < height[j]) i++;
            else j--;
        }
        
        return maxWater;
    }
        

int main() {
     int n;
     cin>>n;

     int arr[n];
     for(int i = 0; i < n; i++){
         cin>>arr[i];
     }

     cout<<maxArea(arr, n);
}
