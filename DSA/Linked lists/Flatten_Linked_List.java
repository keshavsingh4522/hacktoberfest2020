


public class Flatten_Linked_List{
  public Node mergeTwoLists(Node l1, Node l2) {. //Used recursive merge from GitHub
          if(l1 == null){
              return l2;
          }
          if(l2 == null){
              return l1;
          }

          Node mergeHead;
          if(l1.data < l2.data){
              mergeHead = l1;
              mergeHead.bottom = mergeTwoLists(l1.bottom, l2);
          }
          else{
              mergeHead = l2;
              mergeHead.bottom = mergeTwoLists(l1, l2.bottom);
          }
          return mergeHead;
      }

      Node flatten(Node root)
      {
    // Your code here
        //Trying Recursive
        if(root == null){
            return root;
        }

        Node p = flatten(root.next);

        root = mergeTwoLists(root, p);

        return root;









      }
 }     
