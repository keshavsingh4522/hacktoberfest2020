
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<bool>seen(nums.size() + 1);
        int twice;
        for (auto& val : nums) {
            if (seen[val])
                twice = val;
            else
                seen[val] = true;
        }
        for (int i = 1; i < seen.size(); ++i) {
            if (!seen[i]) {
                return vector<int>{twice, i};
            }
        }
        return vector<int>();
    }
};
