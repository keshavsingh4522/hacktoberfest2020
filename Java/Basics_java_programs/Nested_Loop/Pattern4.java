package Basics_java_programs.Nested_Loop;

import java.util.Scanner;

public class Pattern4 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter any Number: ");
        int n = sc.nextInt();
        sc.close();

        for (int j = 1; j <= n; j++) {

            for (int i = 1; i <= n - j; i++) {

                System.out.print("  ");

            }

            for (int i = 1; i <= j; i++) {

                System.out.print("*  ");
            }
            System.out.println();
        }

    }
}
