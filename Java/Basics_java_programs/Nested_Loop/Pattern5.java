package Basics_java_programs.Nested_Loop;

import java.util.Scanner;

public class Pattern5 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter any Number: ");
        int n = sc.nextInt();
        sc.close();

        int number = 1;

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= n - i; j++) {

                System.out.print("  ");
            }

            for (int j = 1; j <= i; j++) {

                System.out.print(number + "  ");
                number++;

            }

            System.out.println();
        }
    }
}
