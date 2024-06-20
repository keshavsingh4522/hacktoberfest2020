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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode *curr=q.front();
                temp.push_back(curr->val);
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->left);
                }
                q.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
