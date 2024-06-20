/*
Min and Max of Binary Tree
For a given a Binary Tree of type integer, find and return the minimum and the maximum data values.
Return the output as an object of Pair class, which is already created.

Note: All the node data will be unique and hence there will always exist a minimum and maximum node data.

Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or 
right node data exist for root, it will not be a part of the node data.

Output Format:
The only line of output prints two integers denoting the minimum and the maximum data values respectively. A single line will separate them both.

Constraints:
2 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec

Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1

Sample Output 1:
1 14


Sample Input 2:
10 20 60 -1 -1 3 50 -1 -1 -1 -1 

Sample Output 2:
3 60
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
#include<climits>
#include<utility>

/*
	The first value of the pair is the minimum value in the tree and 
	the second value of the pair is the maximum value in the tree
*/
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
    //corner case
    if(root == NULL) {
        return {INT_MAX,INT_MIN};
    }
    
    pair<int,int> left = getMinAndMax(root -> left);
    pair<int,int> right = getMinAndMax(root -> right);
    
    //corner case
    if(left.first == INT_MAX and right.first == INT_MAX and left.second == INT_MIN and right.second == INT_MIN) {
        return {root -> data, root -> data};
    }
    
    int curr_MIN = min(left.first, right.first);
    int curr_MAX = max(left.second, right.second);
    
    if(root -> data < curr_MIN) {
        return {root -> data, curr_MAX};
    } else if(root -> data > curr_MAX) {
        return {curr_MIN, root -> data};
    } else {
        return {curr_MIN, curr_MAX};
    }
}
