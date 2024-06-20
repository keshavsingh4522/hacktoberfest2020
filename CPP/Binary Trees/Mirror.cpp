/*
Mirror
For a given Binary Tree of type integer, update it with its corresponding mirror image.

Example:
          1                         1
        /   \                     /   \
      2      3     ----->        3     2
     / \    / \                 / \   / \
    4   5  6   7               7   6  5  4
    Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or 
right node data exist for root, it will not be a part of the node data.

Output Format:
The only line of output prints the mirrored tree in a level-wise order. 
Each level will be printed on a new line. Elements printed at each level will be separated by a single line.

Note:
You are not required to print anything explicitly. It has already been taken care of.

Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec

Sample Input 1:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

Sample Output 1:
1 
3 2 
7 6 5 4


Sample Input 2:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output 2:
5 
6 10 
3 2 
9
 */

/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

*/

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    // Write your code here
    //corner case
    if(root == NULL) {
        return;
    }
    
    mirrorBinaryTree(root -> left);
    mirrorBinaryTree(root -> right);
    
    swap(root -> left, root -> right);
    
    return;
}
