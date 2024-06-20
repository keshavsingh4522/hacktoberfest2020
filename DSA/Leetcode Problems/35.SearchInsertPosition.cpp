class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        nums.push_back(target);
        sort(nums.begin(),nums.end());
        vector<int>::iterator ip; 
        ip = std::unique(nums.begin(), nums.begin() + nums.size()); 
        nums.resize(std::distance(nums.begin(), ip));
        ip = std::find (nums.begin(), nums.end(), target); 
        return ip - nums.begin();
    }
};