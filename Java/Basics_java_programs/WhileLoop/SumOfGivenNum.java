package Basics_java_programs.WhileLoop;

import java.util.Scanner;

public class SumOfGivenNum {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter any number: ");
        int n  = sc.nextInt();
        sc.close();

        int temp = n;
        int sum = 0;

        while (temp > 0) {

            int LastDigit = temp % 10;
            temp /= 10;
            sum += LastDigit;
        }

        System.out.println("The sum  of " + n + " is " + sum);
    }
}
