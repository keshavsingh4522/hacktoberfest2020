package Basics_java_programs.WhileLoop;

import java.util.Scanner;

public class Palindrome {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter any number: ");
        int n  = sc.nextInt();
        sc.close();

        int temp = n;
        int rev = 0;

        while (temp > 0) {

            int LastDigit = temp % 10;
            rev = rev * 10 + LastDigit;
            temp /= 10;
        }
        if (rev == n) {
            System.out.println("The given number is Pallindrome");
        } else {
            System.out.println("The given number is not Pallindrome");
        }
    }
}
