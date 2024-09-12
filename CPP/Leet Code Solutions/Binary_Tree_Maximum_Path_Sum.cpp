//  Link to the problem:
// https://leetcode.com/problems/binary-tree-maximum-path-sum/


// Problem Name=> Binary Tree Maximum Path Sum
// Problem Type=> Hard

// Solution:


class Solution {
public:
    
    int solve(TreeNode* root, int &maxi)
    {
        if(root == NULL) 
            return 0;
        int l = solve(root->left, maxi);
        int r = solve(root->right, maxi);
        
        int ans = l + r + root->val;
        maxi = max(maxi, ans);
        maxi = max(maxi, root->val);
        maxi = max(maxi, root->val + l);
        maxi = max(maxi, root->val + r);
        
        return max(root->val + max(l, r), root->val);
    }
    
    
    int maxPathSum(TreeNode* root) 
    {
        int maxi = INT_MIN;
        int ans = solve(root, maxi);
        return maxi;
        
    }
};










