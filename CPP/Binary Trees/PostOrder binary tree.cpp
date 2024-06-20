/*
Postorder Binary Tree
For a given Binary Tree of integers, print the post-order traversal.

Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or 
right node data exist for root, it will not be a part of the node data.

Output Format:
The only line of output prints the post-order traversal of the given binary tree.

Constraints:
1 <= N <= 10^6
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec

Sample Input 1:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

Sample Output 1:
4 5 2 6 7 3 1 


Sample Input 2:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output 2:
2 9 3 6 10 5 
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

***********************************************************/

void postOrder(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root == NULL) {
        return;
    }
    
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
    
    return;
}
