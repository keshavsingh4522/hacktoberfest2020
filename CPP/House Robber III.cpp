/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   pair<int, int> helper(TreeNode* root)
    {
        if (!root)
            return {0, 0};
        auto l = helper(root->left);
        auto r = helper(root->right);
        int cur_not_rob = max(l.first, l.second) + max(r.first, r.second);
        int cur_rob = l.second + r.second + root->val;
        return {cur_rob, cur_not_rob};
    }
    
    int rob(TreeNode* root) {
        auto res = helper(root);
        return max(res.first, res.second);
    }
};
