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
    
    TreeNode* buildBST(vector<int>& preorder, int& i, int min, int max){
        
        
        if(i==preorder.size() || preorder[i] < min || preorder[i] > max)
           return NULL;
        
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        root->left = buildBST(preorder, i, min, root->val - 1);
    
        root->right = buildBST(preorder, i, root->val + 1, max);
        
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        int min = INT_MIN;
        int max = INT_MAX;
        int ind=0;
        return buildBST(preorder, ind, min, max);
    }
};