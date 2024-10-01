package Basics_java_programs.Nested_Loop;

import java.util.Scanner;

public class Pattern6 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter any Number: ");
        int n = sc.nextInt();
        sc.close();

        int rows = 2 * n - 1;

        for (int i = 1; i <= rows; i++) {

            if (i <= n) {
                for (int j = 1; j <= i; j++) {
                    System.out.print("* ");
                }
            } else {

                for (int j = 1; j <= rows - i + 1; j++) {
                    System.out.print("* ");
                }
            }
            System.out.println();
        }
    }

}
