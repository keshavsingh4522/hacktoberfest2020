import java.util.*;
public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String ch="";
        LinkedList list = new LinkedList();
        do{
        System.out.println("Enter  the value");
        int n = sc.nextInt();
        sc.nextLine();
        list.addNode(n);
        System.out.println("Do you want to add another  node?  Type Yes/No");
        ch = sc.nextLine();
        }while(ch.equals("Yes")); 
        System.out.print("The elements in the linked list are  ");
        list.display();
	} 
}


class LinkedList
{
    class Node
    {
        int data;
        Node next;
        Node(int data,Node temp)
        {
            this.data=data;
            next=temp;
        }
        Node(int data){
            this.data=data;
            this.next=null;
        }
    }
    Node head=null;
    Node tail=null;
    public void addNode(int data) 
    {
        Node node=new Node(data);
        if(head==null){
            head=node;
        }
        else{
            tail.next=node;
        }
        tail=node;
        tail.next=head;
    }
    public void display() 
    { 
     Node temp=head;
     if(head!=null){
         do{
              System.out.print(temp.data+" ");
                temp=temp.next;
         }while(temp!=head);
     }
            
            System.out.println();
    }
}