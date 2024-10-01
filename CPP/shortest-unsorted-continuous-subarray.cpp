//https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        int left=0;
        int right=nums.size()-1;
        
        while (left<right)
        {
            int mini=nums[left];
            int maxi=nums[left];
            
            for(int ind=left;ind<=right;ind++)
            {
                if(nums[ind]<mini)
                {
                    mini=nums[ind];
                }
                
                else if(nums[ind]>maxi)
                {
                    maxi=nums[ind];
                }
            }
            
            bool flag=0;
            
            if(nums[left]==mini)
            {
                left++;
                flag=1;
            }

            if(nums[right]==maxi)
            {
                right--;
                flag=1;
            }
            
            if(flag==0)
            {
                return right-left+1;
            }
        }
        return 0;
    }
};