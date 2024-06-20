class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator ip; 
        ip = std::unique(nums.begin(), nums.end()); 
        nums.resize(std::distance(nums.begin(), ip));
        return nums.size();
    }
};