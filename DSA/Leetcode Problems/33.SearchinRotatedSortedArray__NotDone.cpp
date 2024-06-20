class Solution {
public:
    int binarySearch1(vector<int> nums,target){
        int i=0;
        int j=nums.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(target==nums[mid]){
                return mid;
            }
            else if(target>nums[mid]){
                i=mid+1;
            }
            else if(target < nums[mid]){
                j=mid-1;
            }
        }
    }
    int binarySearch(int arr[], int l, int r, int x)
    {
        if (r >= l) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x)
                return mid;
            if (arr[mid] > x)
                return binarySearch(arr, l, mid - 1, x);
            return binarySearch(arr, mid + 1, r, x);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if(binary_search(nums.begin(),nums.begin()+nums.size(),target)){
            return binarySearch(nums,target);
        }
        else{
            return -1;
        }
        
    }
};