
import java.util.Scanner;

public class PrimeNumber {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        boolean isPrime = true;
        System.out.println("Enter any number: ");
        int n = sc.nextInt();
        sc.close();
        
        for (int i = 2; i < n; i++) {

            if (n % i == 0) {

                isPrime = false;
                break;
            }
        
         }
        if ( n < 2) {

            isPrime = false;
        }
         System.out.println("isPrime " + isPrime);
    }
}