import java.util.Scanner;

public class LargestNumber {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        System.out.print("Enter first number: ");
        int a = input.nextInt();

        System.out.print("Enter second number: ");
        int b = input.nextInt();

        if (a > b) {

            System.out.println("First number is larger");
        } else {

            System.out.println("Second number is larger");
        }
    }
}
