class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l=nums.size()-1;
        
        for(int i=l-1;i>=0;i--)
        {
            if(i+nums[i]>=l)
            {
                l=i;
            }
        }
        if(l==0)
            return true;
        else
            return false;
    }
};