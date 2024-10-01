class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int hi = nums.size()-1;
        int low=0;
        int mid =0;
        
        while(mid<=hi)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else//(nums[mid]==2)
            {
                swap(nums[hi],nums[mid]);
                hi--;
                
                
                
            }
        }
        
        
        
    }
};
