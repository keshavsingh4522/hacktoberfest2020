import java.util.Scanner;

public class Calculator {
    public static void main(String[] args) {
        
        // Taking inputs
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter 1st number");
        int a = sc.nextInt();
        System.out.println("Enter 2nd number");
        int b = sc.nextInt();
        System.out.println("Press 1. for addition\nPress 2. for subtraction\nPress 3 for multiplication\nPress 4. for Division");
        int key_press = sc.nextInt();
        sc.close();

        int result = 0;

        switch (key_press) {

        case 1: 
            result = a + b;
            break;

        case 2: 
            result = a - b;
            break;

        case 3: 
            result = a * b;
            break;

        case 4: 
            result = a / b;
            break;

        default: 
            System.out.println("Enter from number 1 to 4");

        }

        System.out.println("The result is: " + result);
    }
}
