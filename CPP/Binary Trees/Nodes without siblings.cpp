/*
Nodes without sibling
For a given Binary Tree of type integer, print all the nodes without any siblings.

Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the 
left or right node data exist for root, it will not be a part of the node data.

Output Format:
The only line of output prints the node data in a top to down fashion with reference to the root. 
Node data in the left subtree will be printed first and then the right subtree.
A single space will separate them all.

Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 second

Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output 1:
9    


Sample Input 2:
2 4 5 6 -1 -1 7 20 30 80 90 -1 -1 -1 -1 -1 -1 -1 -1

Sample Output 2:
6 7  
*/

/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode
    {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void printNodesWithoutSibling(BinaryTreeNode<int> *root) {
    // Write your code here
    //corner case
    if(root == NULL) {
        return;
    }
    
    if(root -> left == NULL and root -> right) {
        cout << root -> right -> data << " ";
    } else if (root -> left and root -> right == NULL) {
        cout << root -> left -> data << " ";
    }
    
    printNodesWithoutSibling(root -> left);
    printNodesWithoutSibling(root -> right);
  
}
