class Solution {
    
    public int diameterOfBinaryTree(TreeNode root) {
         if(root==null)
            return 0;
      int l= diameterOfBinaryTree(root.left);
      int  r= diameterOfBinaryTree(root.right);
      int lh=height(root.left);
        int rh=height(root.right);
        return Math.max(lh+rh,Math.max(l,r));
          
    }
    public int height(TreeNode root){
        if(root==null)
            return 0;
     int left= height(root.left);
     int right= height(root.right);
        return (1+Math.max(left,right));
    } 
}
