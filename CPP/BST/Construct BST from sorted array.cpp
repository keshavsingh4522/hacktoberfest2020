/*
Construct BST from a Sorted Array
Given a sorted integer array A of size n, which contains all unique elements. You need to construct a balanced BST from this input array. 
Return the root of constructed BST.

Note: If array size is even, take first mid as root.

Input format:
The first line of input contains an integer, which denotes the value of n. The following line contains n space separated integers, 
that denote the values of array.

Output Format:
The first and only line of output contains values of BST nodes, printed in pre order traversal.

Constraints:
Time Limit: 1 second

Sample Input 1:
7
1 2 3 4 5 6 7

Sample Output 1:
4 2 1 3 6 5 7 
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
BinaryTreeNode<int>* helper(int *input, int startIndex, int endIndex) {
    //base case
    if(startIndex > endIndex) {
        return NULL;
    }
    
    int mid = startIndex + (endIndex - startIndex) / 2;
    
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(input[mid]);
    root -> left = helper(input, startIndex, mid - 1);
    root -> right = helper(input,mid + 1, endIndex);
    
    return root;
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
	// Write your code here
    return helper(input, 0, n - 1);
}
