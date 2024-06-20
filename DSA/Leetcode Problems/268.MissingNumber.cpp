class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        sort(nums.begin(), nums.end());
        for(; i < nums.size(); ++i)
        {
            if(nums[i] != i)
                return i;
        }
        return i;
    }
};