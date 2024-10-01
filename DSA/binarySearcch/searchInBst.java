package Algo.binarySearcch;

class Node{
	Node left , right;
	int data;
	
	public Node(int data) {
		this.data = data;
		left = null;
		right = null;
	}
}

public class searchInBst {

		
	
	static Node searchBst(Node root , int key) {
		
		if(root==null) {
			return null;
		}
		
		if(root.data==key) {
			return root;
		}
		if(root.data> key) {
			return searchBst(root.left , key);
		}
		
			return searchBst(root.right,key);	
	} 
	
	public static void main(String[] args) {
		Node root = new Node(4);
		root.left = new Node(2);
		root.right = new Node(5);
		root.left.left = new Node(1);
		root.left.right = new Node(3);
		root.right.right = new Node(6); 
		
		if(searchBst(root ,5)==null) {
			System.out.println("key dosen't exist");
		}
		else {
			System.out.println("key exists");
		}
	}

}
