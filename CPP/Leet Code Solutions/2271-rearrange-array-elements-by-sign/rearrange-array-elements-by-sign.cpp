class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positives, negatives; // Separate vectors for positive and negative numbers

        // Separate the numbers into positives and negatives
        for (int num : nums) {
            if (num < 0) {
                negatives.push_back(num);
            } else {
                positives.push_back(num);
            }
        }

        vector<int> ans(nums.size()); // Initialize the answer vector with the correct size
        int posIndex = 0, negIndex = 0; // Indices for positives and negatives

        // Fill the ans vector by alternating between positives and negatives
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                ans[i] = positives[posIndex++];
            } else {
                ans[i] = negatives[negIndex++];
            }
        }

        return ans;
    }
};