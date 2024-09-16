class DoublyLinkedList {
    //A node class for doubly linked list
    class Node{
        String vil; // village/town name in Botswana
        Node prev; // points to the previous village
        Node next; // points to the next village
        public Node(String vil) { // constructor
            this.vil = vil;
        }
    }
    //Initially,

    Node head, tail = null;
    // let two pointers identify the first and the last nodes
    //add a node to the list
    public void addNodeToEnd(String vil) {
        //Create a new node
        Node newNode = new Node(vil);
        //if list is empty, head and tail points to newNode
        if(head == null) {
            head = tail = newNode;
            //head's prev will be null
            head.prev = null;
            //tail's next will be null
            tail.next = null;
        }
        else {
            //add newNode to the end of list. tail->next set to newNode
            tail.next = newNode;
            //newNode->prev set to tail
            newNode.prev = tail;
            //newNode becomes new tail
            tail = newNode;
            //tail's next point to null
            tail.next = null;
        }
    }

    public Node deleteLastNode(){
        if(head== null){
            return null;
        }
        else{
            if(head!= tail){
                tail= tail.prev;
                tail.next= null;
            }
            else{
                head= tail= null;
            }
        }
        return tail;
    }

    public void printNodes() {
        //Node current will point to head
        Node current = head;
        if(head == null) {
            System.out.println("Doubly linked list is empty");
            return;
        }
        System.out.println("Nodes of doubly linked list: ");
        while(current != null) {
            //Print each node and then go to next.
            System.out.println(current.vil + " ");
            current = current.next;
        }
    }

    public void addNodeToFront(String village){
        Node newNode= new Node(village);

        if(head== null){
            head= tail= newNode;
            head.prev= null;
            tail.next= null;
        }
        else{
            head.prev= newNode;
            newNode.next= head;
            newNode.prev= null;
            head= newNode;
        }
    }

    public void addNodeBefore(String T, String Vil){
        Node p= null;
        Node current= head;
        boolean isPresent= false;
        while(current!=null){
            if(current.vil.equalsIgnoreCase(Vil)){
                isPresent= true;
                p= current;
                break;
            }
            current= current.next;
        }
        if(!isPresent){
            System.out.println("Given node NOT FOUND");
            return;
        }
        Node newNode= new Node(T);
        newNode.next=p;
        newNode.prev=p.prev;
        p.prev= newNode;
        if(newNode.prev!=null){
            newNode.prev.next= newNode;
        }
        else{
            newNode.prev.next= newNode;
        }
    }

    public Node deleteNodeBefore(String T, String Vil){
        if(head== null){
            return null;
        }
        Node temp= null;
        Node current= head;
        boolean isPresent= false;
        while(current!= null){
            if(current.vil.equalsIgnoreCase(Vil)){
                isPresent= true;
                //??
                break;
            }
            else{
                //??
            }
        }
        if(!isPresent){
            System.out.println("Node given NOT FOUND therefore i cant delete");
            return null;
        }
        return current;
    }
    
    
    public void addNodeAfterNode(String t,String vil){
     Node prevNode = null;
     Node current = head;
     
     if(current == null){
     Node newNode = new Node(t);
     head = tail = newNode;
     head.prev = null;
     tail.next = null;
     }
     
     while((!current.vil.equalsIgnoreCase(vil)) && current != null){
       current =current.next;
     }
     if(current.vil.equalsIgnoreCase(vil)){
      Node newNode = new Node(t);
      newNode.next = prevNode.next;
      prevNode.next = newNode;
      newNode.prev = prevNode;
     }else{
     System.out.println("The node was not found");
     }
     
    }
    
    public Node deleteNodeAfter(String T,String vil){
    
        if(head== null){
         System.out.print("List is empty");
            return null;
        }
        Node temp= null;
        Node current= head;
        
            while((!current.vil.equals(vil)) && current!= null){
               current = current.next;
             }
        
        if(current.vil.equals(vil)){
        temp = current.next;
        current.next = temp.next;
        temp.next.prev = current;
        }else{
         System.out.println("Node given NOT FOUND therefore i cant delete");
         return null;
        }
        return current;
    }

    
}