package Basics_java_programs.Nested_Loop;

import java.util.Scanner;

public class Pattern3 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter any Number: ");
        int n = sc.nextInt();
        sc.close();
        
        for (int j = 1; j <=n; j++) {

            for(int i = 1; i <= n-j+1; i++) {

                System.out.print("*" +" ");
            }
            System.out.println();
        }

    }
}
