import java.awt.desktop.SystemEventListener;
import java.util.Scanner;

public class CurrencyConverter {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        System.out.print("Enter your money in Indian Rupee: ");
        float rupee = input.nextFloat();

        float dollar = rupee / 74.11f;

        System.out.println("Your converted Dollar is: " + dollar);

    }
}
