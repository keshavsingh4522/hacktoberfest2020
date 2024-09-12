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
    unordered_map<int, int> freq;
    
    int dfs(TreeNode* root){
        if(!root) return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        int curr = left + right + root->val;
        
        freq[curr]++;
        return curr;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        int maxF = INT_MIN;
    
        for(auto x: freq) maxF = max(maxF, x.second);
        
        vector<int> res;
        for(auto x: freq) if(x.second == maxF) res.push_back(x.first);
        
        return res;
    }
};
