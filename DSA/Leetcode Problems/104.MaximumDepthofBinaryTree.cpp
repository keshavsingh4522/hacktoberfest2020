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
    int maxDepth(TreeNode* node) {
        int x=0,y=0;
        if(node==NULL){
            return 0;
        }
        x=maxDepth(node->left);
        y=maxDepth(node->right);
        if(x>y) return x+1;
        else    return y+1;
    }
};

//gfg
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        int x=0,y=0;
        if(node==NULL){
            return 0;
        }
        x=height(node->left);
        y=height(node->right);
        if(x>y) return x+1;
        else    return y+1;
    }
};
