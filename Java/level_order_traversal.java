//https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/

public class levelordertraversal {
    public List<List<Integer>> levelOrder(TreeNode root) {
        
        if(root==null)
        {
            return new ArrayList<>();
        }
        TreeNode s=new TreeNode(Integer.MAX_VALUE);
        ArrayDeque<TreeNode> q=new ArrayDeque<>();
        //boolean vist[]=new boolean[]
        q.add(s);
        q.add(root);
        ArrayList<Integer> al=new ArrayList<>();
        List<List<Integer>> ans=new ArrayList<>();
        while(q.size()>0)
        {
            TreeNode top=q.remove();
            if(top==s)
            {
                if(q.size()>0){
                q.add(s);}
                if(al.size()>0)
                {
                    ans.add(al);
                    al=new ArrayList<>();
                }
            }
            else
            {
                al.add(top.val);
                
                if(top.left!=null) q.add(top.left);
                if(top.right!=null) q.add(top.right);
                
            }
        }
        
        return ans;
    }
}
