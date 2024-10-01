package For_Loop;

import java.util.Scanner;

public class Fiboncci {

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int a = 0;
        int b = 1;
        sc.close();
        
        System.out.print(a + " ");
        System.out.print(b + " ");


        // as we are printing 2 numbers first so loop till n-2
        for (int i = 1; i <= n-2; i++) {

            int c = a + b;
            System.out.print(c + " ");

            a = b;
            b = c;


        }
    }
}