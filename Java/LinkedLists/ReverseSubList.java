//Name-----Saurabh Tripathi


import java.io.*;
import java.util.*;
class Node
    {
        int data;
        Node next;
        Node(int d) {data = d; next = null; }
    }
class insertion
{
    Node head;  
    Node tail;
	public void addToTheLast(Node node) 
	{
	  if (head == null) 
	  {
	   head = node;
	   tail = node;
	  } 
	  else 
	  {
	   tail.next = node;
	   tail = node;
	  }
	}
      void printList(Node head)
    {
        Node temp = head;
        while (temp != null)
        {
           System.out.print(temp.data+" ");
           temp = temp.next;
        }  
        System.out.println();
    }
	/* Drier program to test above functions */
	public static void main(String args[])throws IOException
    {
         BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // Scanner sc = new Scanner(System.in);
		 int t=Integer.parseInt(br.readLine());
		 while(t>0)
         {
            String S[] = br.readLine().split(" ");
			int N = Integer.parseInt(S[0]);
            int m = Integer.parseInt(S[1]);
            int n = Integer.parseInt(S[2]);
		
		    String S1[] = br.readLine().split(" ");
			insertion llist = new insertion(); 
			int a1=Integer.parseInt(S1[0]);
			Node head= new Node(a1);
            llist.addToTheLast(head);
            for (int i = 1; i < N; i++) 
			{
				int a = Integer.parseInt(S1[i]);
				llist.addToTheLast(new Node(a));
			}
			
        Solution ob = new Solution();
		Node newhead=ob.reverseBetween(llist.head, m, n);
		llist.printList(newhead);
		
        t--;		
        }
    }}// } Driver Code Ends


//User function Template for Java

/*
class Node
    {
        int data;
        Node next;
        Node(int d) {data = d; next = null; }
    }
    */
class Solution
{
    public static Node reverseBetween(Node head, int m, int n)
    {
        if(m == n)
          return head;
          
        int i=1;
        Node temp = head;
        Node prev = null;
        while(i<m)
        {
            prev = temp;
            temp = temp.next;
            i++;
        }
        Node start = temp;
        while(i<n)
        {
            temp=temp.next;
            i++;
        }
        
        Node end = temp;
        Node next = temp.next;
        end.next = null;
        
        Node rev = reverse(start);
        
        if(prev!=null)
        {
            prev.next.next = next;
            prev.next = rev;
        }
        else
        {
            if(next!=null)
            {
                head.next = next;
            }
            head = rev;
        }
    
         return head;
    }
    
     public static Node reverse(Node head)
    {
        Node curr=head;
        Node prev=null;
        Node next=null;
        while(curr!=null)
        {
          next = curr.next;
          curr.next = prev;
          prev = curr;
          curr = next;
        }
        
        return prev; 
    }
}