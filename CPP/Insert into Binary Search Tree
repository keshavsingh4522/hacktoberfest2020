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
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        TreeNode* head=root;
        TreeNode* temp=new TreeNode(val);
                if(root==NULL){
            return temp;
        }
       while(true){
           if(root->val>=val){
               if(root->left){
                   root=root->left;
               }
               else{
                   root->left=temp;
                   return head;
               }
           }
           else {
               if(root->right){
                   root=root->right;
               }
               else{
                   root->right=temp;
                   return head;
               }
           }
       }
        return root;
    }
};
