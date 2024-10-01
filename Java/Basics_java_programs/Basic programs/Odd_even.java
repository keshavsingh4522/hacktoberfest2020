import java.util.Scanner;

public class Odd_even {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter any number: ");
        
        int a = sc.nextInt();
        sc.close();

        if (a % 2 == 0) {

            System.out.println("Given number is even!");
        }
        else {

            System.out.println("Given number is Odd!");
        }
    }
}
