import java.util.Scanner;
public class AdditionFunction {

    public static void main(String[] args) {

        int x = Add();
        System.out.println(x);
    }

    static int Add() {

        Scanner input = new Scanner(System.in);
        System.out.print("Enter First number: ");
        int a = input.nextInt();

        System.out.print("Enter Second number: ");
        int b = input.nextInt();

        int c = a + b;
        return c;


    }
}