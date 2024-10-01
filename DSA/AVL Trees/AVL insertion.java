import java.io.*;
import java.util.*;

public class pair
{
    int first;
    boolean second;
    pair(int first, boolean second)
        {
            this.first = first;
            this.second = second;
        }
}
class Node
{
    int data, height;
    Node left, right;
    
    Node(int x)
    {
        data=x;
        left=right=null;
        height=1;
    }
}
class GfG
{
    public static boolean isBST(Node n, int lower, int upper)
    {
    	if(n==null) return true;
    	if( n.data <= lower || n.data >= upper ) return false;
    	return isBST(n.left, lower, n.data) && isBST(n.right, n.data, upper) ;
    }
    
    public static pair isBalanced(Node n)
    {
    	if(n==null)
    	    {
    	        return new pair(0,true);
    	    }
        
    	pair l = isBalanced(n.left);
    	pair r = isBalanced(n.right);
    
    	if( Math.abs(l.first - r.first) > 1 ) return new pair (0,false);
    
    	return new pair( 1 + Math.max(l.first , r.first) , l.second && r.second );
    }
    
    public static boolean isBalancedBST(Node root)
    {
    	if( isBST(root, Integer.MIN_VALUE , Integer.MAX_VALUE) == false )
    		System.out.print("BST voilated, inorder traversal : ");
    
    	else if ( isBalanced(root).second == false)
    		System.out.print("Unbalanced BST, inorder traversal : ");
    
    	else return true;
    	return false;
    }
    
    public static void printInorder(Node n)
    {
    	if(n==null) return;
    	printInorder(n.left);
    	System.out.print(n.data + " ");
    	printInorder(n.right);
    }


    public static void main(String args[])
        {
            int ip[] = new int[2000];
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    int n = sc.nextInt();
                    for(int i = 0; i < n; i++)
                        {
                            ip[i] = sc.nextInt();
                        }
                        
                    Node root = null;
                    Solution obj = new Solution();
                    for(int i=0; i<n; i++)
                    {
                        root = obj.insertToAVL( root, ip[i] );
                        
                        if ( isBalancedBST(root) == false )
                            break;
                    }
                    
                    printInorder(root);
                    System.out.println();
                    
                }
            
                
        }
}// } Driver Code Ends


//User function Template for Java

/*
class Node
{
    int data;
    Node left;
    Node right;
    int height;
};
*/
class Solution
{
    public Node insertToAVL(Node node,int element)
    {
        if (node == null) {
            return new Node(element);
        }

        if (node.data > element) {
            node.left = this.insertToAVL(node.left, element);
        } else if (node.data < element) {
            node.right = this.insertToAVL(node.right, element);
        }

        int balanceFactor = calculateHeight(node.left) - calculateHeight(node.right);

        if (balanceFactor >= 2) {
            if (node.left.data > element) {
                return this.rightRotation(node);
            } else {
                node.left = this.leftRotation(node.left);
                return this.rightRotation(node);
            }
        } else if (balanceFactor <= -2) {
            if (node.right.data < element) {
                return this.leftRotation(node);
            } else {
                node.right = this.rightRotation(node.right);
                return this.leftRotation(node);
            }
        }

        return node;
    }
    
   private Node leftRotation(Node node) {
        Node newRoot = node.right;
        Node newRootLeft = newRoot.left;

        node.right = newRootLeft;
        newRoot.left = node;

        return newRoot;
    }

    private Node rightRotation(Node node) {
        Node newRoot = node.left;
        Node newRootRight = newRoot.right;

        node.left = newRootRight;
        newRoot.right = node;

        return newRoot;
    }
    
     private int calculateHeight(Node node) {
        if (node == null) {
            return 0;
        }

        return 1 + Math.max(calculateHeight(node.left), calculateHeight(node.right));
    }
}    
