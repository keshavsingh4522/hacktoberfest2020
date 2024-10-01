// Definition for a binary tree node.
public class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int val) { 
        this.val = val; 
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class LevelOrderTraversal {
        public List<List<Integer>> levelOrder(TreeNode root) {
        
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        
        if(root == null) return res;
        
        ArrayDeque<TreeNode> queue = new ArrayDeque<TreeNode>();
        queue.offer(root); // queue.add(root);
        
        while(!queue.isEmpty()) {
            
            List<Integer> level = new ArrayList<Integer>();
            int size = queue.size();
                
            for(int i=0; i<size; i++) {             
                TreeNode cur = queue.poll();
                
                level.add(cur.val);
                
                if(cur.left != null) queue.offer(cur.left);
                if(cur.right != null) queue.offer(cur.right);
            }
            
            res.add(level);
        }
        
        return res;
    }
}