/*
Find a node

For a given Binary Tree of type integer and a number X, find whether a node exists in the tree with data X or not.
 
Input Format:
The first line of each test case contains elements of the first tree in the level order form. The line consists of values of nodes separated by a single space. 
In case a node is null, we take -1 in its place.
The second line of each test case contains the node value you have to find.

Output Format:
The only line of output prints 'true' or 'false'.

The output of each test case should be printed in a separate line.

Note:
You are not required to print anything explicitly. It has already been taken care of.

Constraints:
1 <= N <= 10^5

Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec.

Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
7

Sample Output 1:
true
Explanation For Output 1:
Clearly, we can see that 7 is present in the tree. So, the output will be true.


Sample Input 2:
2 3 4 -1 -1 -1 -1
10

Sample Output 2:
false
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

bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    // Write your code here
    if(root == NULL) {
        return false;
    }
    
    if(root -> data == x) {
        return true;
    }
    
    return isNodePresent(root -> left, x) or isNodePresent(root -> right, x);   
}
