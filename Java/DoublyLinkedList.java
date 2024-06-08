//This program implements a Doubly Linked List.
//This program is fully functional.
import java.util.*;
class DoublyLinkedList
{
	Node head=null;
	Node tail=null;
	Node newnode;
	Scanner sc=new Scanner(System.in);
	void create()
	{
		int val;
		int choice=1;
		while(choice==1)
		{
			System.out.println("Enter data for node: ");
			val=sc.nextInt();
			newnode=new Node();
			newnode.data=val;
			newnode.next=null;
			newnode.prev=null;
			if(head==null)
			{
				head=newnode;
				tail=newnode;
				head.next=null;
				head.prev=null;
				tail.next=null;
				tail.prev=null;
			}
			else
			{
				tail.next=newnode;
				newnode.prev=tail;
				tail=tail.next;
			}
			System.out.println("If you wish to add another node press 1 else press 0 to stop.");
			choice=sc.nextInt();
			if(choice==1)
				continue;
			else
				break;
		}
		show();
	}
	void show()
	{
		if(head==null)
			System.out.println("Linked List is Empty!");
		else
		{
			Node n=head;
			System.out.print("Linked List:\t");
			while(n!=null)
			{
				System.out.print(n.data+"\t");
				n=n.next;
			}
			System.out.println();
		}
	}
	void insertatbeg(int val)
	{
		Node n=new Node();
		n.data=val;
		n.next=null;
		n.prev=null;
		if(head==null)
			head=tail=n;
		else
		{
			n.next=head;
			head.prev=n;
			head=n;
		}
		show();
	}
	void insertatend(int val)
	{
		Node n=new Node();
		n.data=val;
		n.next=null;
		n.prev=null;
		if(head==null)
			head=tail=n;
		else
		{
			tail.next=n;
			n.prev=tail;
			tail=n;
		}
		show();
	}
	void insertatpos()
	{
		int val, index;
		System.out.println("Enter a value to append:");
		val=sc.nextInt();
		System.out.println("Enter an index to append that value at:");
		index=sc.nextInt();
		int length=length_return();
		if(index==0)
			insertatbeg(val);
		else if(index==length)
			insertatend(val);
		else
		{
			Node n=new Node();
			n.data=val;
			n.next=null;
			n.prev=null;
			Node temp=head;
			for(int i=0;i<index-1;i++)
				temp=temp.next;
			n.next=temp.next;
			n.prev=temp;
			temp.next=n;
			temp=temp.next;
			temp.prev=n;
			show();
		}
	}
	void deleteatbeg()
	{
		if(head==null)
			System.out.println("The linked list is empty!");
		else
		{
			System.out.println("The value "+head.data+" was removed from the start of the linked list.");
			head=head.next;
			if(head==null)
				tail=null;
			else
				head.prev=null;
			show();
		}
	}
	void deleteatend()
	{
		if(tail==null)
			System.out.println("The linked list is empty!");
		else
		{
			System.out.println("The value "+tail.data+" was removed from the end of the linked list.");
			tail=tail.prev;
			if(tail==null)		//If while removing the last element, the tail becomes null
				head=null;		//we make head null as well to make the list empty.
			else
				tail.next=null;	//Otherwise, we remove the connection of last node from list.
		}
		show();
	}
	void deleteatpos()
	{
		System.out.println("Enter index you want to remove value from: ");
		int index=sc.nextInt();
		int length=length_return();
		if(length==0)
			System.out.println("Cannot delete element! Linked List is empty!");
		else if(index>=length || index<0)
			System.out.println("Error! Invalid index position entered!");
		else if(index==0)
			deleteatbeg();
		else
		{
			Node n=head;
			for(int i=0;i<index-1;i++)
				n=n.next;
			Node back=n;
			n=n.next;
			n=n.next;
			Node front=n;
			front.prev=back;
			back.next=front;
			show();
		}
	}
	void length_show()
	{
		Node n=head;
		int length=0;
		while(n!=null)
		{
			length++;
			n=n.next;
		}
		System.out.println("Length of doubly linked list: "+length);
	}
	int length_return()
	{
		Node n=head;
		int length=0;
		while(n!=null)
		{
			length++;
			n=n.next;
		}
		return length;
	}
	void reverse()
	{
		if(head==null)
			System.out.println("The compiler is unable to reverse a list that hasn't been created yet.");
		else
		{
			System.out.print("Before reversal ");
			show();
			Node currentnode=head;
			Node nextnode;
			while(currentnode!=null)
			{
				nextnode=currentnode.next;
				currentnode.next=currentnode.prev;
				currentnode.prev=nextnode;
				currentnode=nextnode;
			}
	        currentnode=head;
	        head=tail;
	        tail=currentnode;
			System.out.print("After reversal ");
			show();
			System.out.println();
			}
		}
	public static void main(String args[])
	{
		DoublyLinkedList ob=new DoublyLinkedList();
		ob.reverse();
		
	}
}
