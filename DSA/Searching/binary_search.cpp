#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        return bs(nums,target,l,r);
    }
    int bs(vector<int> v,int x,int l,int r){
        int mid=0;
        if(l<=r){
            mid=(r+l)/2;
        
        if(v[mid]==x){
            return mid;
        }
        if(v[mid]<x){
            return bs(v,x,mid+1,r);
        }
        return bs(v,x,l,mid-1);
        }
        return -1;
    }

int main()
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	int result = search(arr, 0, n - 1, x);
	(result == -1) ? cout << "Element is not present in array"
				: cout << "Element is present at index " << result;
	return 0;
}
