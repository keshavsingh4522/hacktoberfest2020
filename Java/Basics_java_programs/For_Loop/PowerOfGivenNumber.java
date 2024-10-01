

import java.util.Scanner;

public class PowerOfGivenNumber {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a number!");
        int a = sc.nextInt();

        System.out.println("Enter the power number");
        int n = sc.nextInt();
        int result = 1;
        sc.close();
        
        for (int i = 0; i < n; i++) {

            result *= a;
        }
        System.out.println(result);
    }
}
