
public class BinaryTree {
    static class Node{
        int data ;
        Node left;
        Node right;

        Node(int data){
            this.data =data;
            this.left = null;
            this.right = null;
        }
    }

    static class BinaryTree{
        static int idx =-1;
        public static Node buildTree(int nodes[]){
             idx++;
             if(node[idx]==-1){
                return null;
             }

             Node newNode = new Node(nodes[idx]);
             newNode.left = builtTree(nodes);
             newNode.right = builtTree(nodes);

             return newNode;
        }
    }
    public static void main(String[] args){
        int nodes[] = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1}; // given in preorder sequence
        BinaryTree tree = new BinaryTree();
       Node root =  tree.buildTree(nodes);
       System.out.println(root.data);
    }
    private BinaryTree.Node buildTree(int[] nodes) {
        return null;
    }
}
