class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result;
        int temp=0;
        for(int i=0;i<nums.size();i++){
            temp=temp+nums[i];
            result.push_back(temp);
        }
        return result;
    }
};