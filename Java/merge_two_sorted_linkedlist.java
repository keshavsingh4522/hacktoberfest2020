import java.io.*;
import java.util.*;

public class Main {
    public static class Node {
        int data;
        Node next;
    }

    public static class LinkedList {
        Node head;
        Node tail;
        int size;

        void addLast(int val) {
            Node temp = new Node();
            temp.data = val;
            temp.next = null;

            if (size == 0) {
                head = tail = temp;
            } else {
                tail.next = temp;
                tail = temp;
            }

            size++;
        }

        public int size() {
            return size;
        }

        public void display() {
            for (Node temp = head; temp != null; temp = temp.next) {
                System.out.print(temp.data + " ");
            }
            System.out.println();
        }

        public void addFirst(int val) {
            Node temp = new Node();
            temp.data = val;
            temp.next = head;
            head = temp;

            if (size == 0) {
                tail = temp;
            }

            size++;
        }

     
 public static LinkedList mergeTwoSortedLists(LinkedList l1, LinkedList l2) {
          
            LinkedList res = new LinkedList();
            
            Node o=l1.head;
            Node t=l2.head;
            
            while(o!=null && t!=null)
            {
                if(o.data<t.data)
                {
                    res.addLast(o.data);
                   o=o.next;
                }
                else
                {
                     res.addLast(t.data);
                   t=t.next;
                }
            }
            
            while(o!=null)
            {
                 res.addLast(o.data);
                    o=o.next;
            }
            
            
            while(t!=null)
            {
                  res.addLast(t.data);
                    t=t.next;
            }
            
            
            
            return res;
            
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n1 = Integer.parseInt(br.readLine());
        LinkedList l1 = new LinkedList();
        String[] values1 = br.readLine().split(" ");
        for (int i = 0; i < n1; i++) {
            int d = Integer.parseInt(values1[i]);
            l1.addLast(d);
        }

        int n2 = Integer.parseInt(br.readLine());
        LinkedList l2 = new LinkedList();
        String[] values2 = br.readLine().split(" ");
        for (int i = 0; i < n2; i++) {
            int d = Integer.parseInt(values2[i]);
            l2.addLast(d);
        }

        LinkedList merged = LinkedList.mergeTwoSortedLists(l1, l2);
        merged.display();
       
    //    example inputs are l1: 10 20 30 40 50 
//  l2: 7 9 12 15 37 43 44 48 52 56 
    }
}