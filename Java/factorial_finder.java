// These code is for finding factorial of numbers and is written in java language
// This can find factorial for bigger numbers also
// This is written with using concept of linked list
// IDE used - IntelliJ IDEA
// Author - Nilesh chaudhary


import java.util.*;
import java.lang.*;

class Solution {
    static class Node{
        int data;
        Node prev;
        Node(int data){
            this.data = data;
            this.prev = null;
        }
    }
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter test cases : ");
        int t = s.nextInt();
        while(t-- > 0){
            int n;
            System.out.print("Enter number for finding factorial : ");
            n = s.nextInt();
            Node tail = new Node(1);
            for (int i = 2;i <= n; i++)
                multiply(tail,i);
            print(tail);
            System.out.println();
        }
    }
    private static void print(Node tail){
        if(tail == null){
            return;
        }
        print(tail.prev);
        System.out.print(tail.data);
    }
    private static void multiply(Node tail,int n){
        Node temp = tail ,prevNode = tail;
        int carry = 0;
        while(temp != null){
            int data = temp.data*n + carry;
            temp.data = data % 10;
            carry = data/10;
            prevNode = temp;
            temp = temp.prev;
        }
        while(carry != 0){
            prevNode.prev = new Node((int)(carry%10));
            carry/=10;
            prevNode = prevNode.prev;
        }
    }
}
//    Example
//    Enter test cases : 1
//    Enter number for finding factorial :
//    100
//    93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000
