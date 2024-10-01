import java.util.Scanner;

public class singlylinklist {

    private Node head;

    public static class Node {
        private int data;
        private Node next;

        public Node(int data) {
            this.data = data;
            this.next = null;
        }

    }

    public void display(Node current) {

        while (current != null) {
            System.out.print(current.data + " --> ");
            current = current.next;
        }

        System.out.println("Null");
    }

    public void Length() {
        Node current = head;
        int count = 0;

        while (current != null) {
            count++;
            current = current.next;
        }

        System.out.println("Length Of the Singly Link List is :- " + count);
    }

    public void InsertionAtBeginning(int value) {
        Node New_Node = new Node(value);
        New_Node.next = head;
        head = New_Node;
    }

    public void InsertionAtEnd(int value) {
        Node New_Node = new Node(value);
        Node current = head;
        if (head == null) {
            head = New_Node;
        } else {
            while (current.next != null) {
                current = current.next;
            }
            current.next = New_Node;
        }
    }

    public void AtPos(int pos, int value) {
        Node New_Node = new Node(value);
        Node temp = head, current = head;
        int i = 1;
        while (i < pos) {
            temp = current;
            current = current.next;
            i++;
        }
        temp.next = New_Node;
        New_Node.next = current;
    }

    public Node DeleteFirst() {
        if (head == null) {
            return null;
        }
        Node temp = head;
        head = head.next;
        temp.next = null;
        return head;

    }

    public Node DeleteLast() {
        if (head == null) {
            return null;
        }
        Node current = head;
        Node prev = head;
        if (head.next == null) {
            head = null;
            return head;
        } else {
            while (current.next != null) {
                prev = current;
                current = current.next;
            }
        }

        prev.next = null;
        return prev;

    }

    public void DeleteAtPos(int pos) {
        int count = 1;
        Node current = head;
        if (pos == 1) {
            DeleteFirst();

        }

        else {
            while (count < pos - 1) {

                current = current.next;
                count++;

            }

            Node temp = current.next;
            current.next = temp.next;
        }
    }

    public void searchData(int data) {
        Node current = head;
        int pos = 1;
        int flag = 0;
        while (current != null) {
            if (current.data == data) {
                flag = 1;
                System.out.println("Found at position : " + pos);
                break;
            }
            current = current.next;
            pos++;
        }
        if (flag == 0) {
            System.out.println("Not Found");
        }
    }
        public static singlylinklist reverse(singlylinklist head) {
        singlylinklist next = null;
        singlylinklist current = head;
        singlylinklist previous = null;
        while(current!=null)
        {
            next = current.next;
            current.next = previous;
            previous = current;
            current = next;
        }
        singlylinklist singlyLinkedList = previous;
        return singlyLinkedList;

}



    public int FindNthNode(int n) {
        Node current = head;
        Node prev = head;
        int count = 0;
        while (count < n) {
            current = current.next;
            count++;
        }

        while (current != null) {
            current = current.next;
            prev = prev.next;
        }
        return prev.data;

    }

    public int MiddleNode(){
        Node twoJump = head;
        Node oneJump = head;

        while(twoJump != null && twoJump.next != null){
            twoJump = twoJump.next.next;
            oneJump = oneJump.next;
        }
        return oneJump.data;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        singlylinklist cr = new singlylinklist();

        do {
            System.out.println("|       Press 0 for Exit.            |");
            System.out.println("|       Press 1 for Insert.          |");
            System.out.println("|       Press 2 for Display.         |");
            System.out.println("|       Press 3 For Length.          |");
            System.out.println("| Press 4 for Insert at Beginning.   |");
            System.out.println("|    Press 5 for Insert at End.      |");
            System.out.println("|  Press 6 For Insert At Position    |");
            System.out.println("|  Press 7 For Delete 1st Node       |");
            System.out.println("|  Press 8 To Delete Last Node       |");
            System.out.println("|  Press 9 To Delete At Position     |");
            System.out.println("|    Press 10 To Search A Data       |");
            System.out.println("|       Press 11 To Reverse          |");
            System.out.println("|Press 12 To find nth Node From Last.|");
            System.out.println("|     Press 13 to Find Middle Node   |");
            System.out.println();
            System.out.println("Enter Your Choice Here : ");
            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("Enter The Data : ");
                    int value_insert = sc.nextInt();
                    cr.InsertionAtEnd(value_insert);
                    break;

                case 2:
                    cr.display(cr.head);
                    break;

                case 3:
                    cr.Length();
                    break;

                case 4:
                    System.out.println("Enter The Data : ");
                    int value_beg = sc.nextInt();
                    cr.InsertionAtBeginning(value_beg);
                    break;

                case 5:
                    System.out.println("Enter The Data : ");
                    int value_end = sc.nextInt();
                    cr.InsertionAtEnd(value_end);
                    break;

                case 6:
                    int pos, value_pos;
                    System.out.println("Enter the Position And Data : ");
                    pos = sc.nextInt();
                    value_pos = sc.nextInt();
                    cr.AtPos(pos, value_pos);
                    break;

                case 7:
                    cr.DeleteFirst();
                    break;

                case 8:
                    cr.DeleteLast();
                    break;

                case 9:
                    System.out.println("Enter the Position of The Node you Want To Delete : ");
                    int value_delPos = sc.nextInt();
                    cr.DeleteAtPos(value_delPos);
                    break;

                case 10:
                    System.out.println("Enter The Data you want to search : ");
                    int search_value = sc.nextInt();
                    cr.searchData(search_value);
                    break;

                case 11:
                    cr.display(cr.singlylinklist Reverse(cr.head));

                    break;

                case 12:
                    System.out.println("Enter the value of n : ");
                    int n = sc.nextInt();
                    System.out.println("Nth Node from the last is  : " + cr.FindNthNode(n));
                    break;

                case 13:
                    System.out.println("Middel Node of the Give Link List is : " + cr.MiddleNode());
                    break;

                case 0:
                    System.exit(0);
                    break;

                default:
                    System.out.println("Please Select Correct Option.");
                    break;
            }

        } while (true);

        // cr.head = new Node(10);
        // Node second = new Node(20);
        // Node third = new Node(30);
        // Node fourth = new Node(40);

        // cr.head.next = second;
        // second.next = third;
        // third.next = fourth;

        // cr.display();
        // cr.Length();
        // Node NewNode = new Node(50);
        // cr.InsertionAtEnd(NewNode);
        // cr.display();

    }

}
