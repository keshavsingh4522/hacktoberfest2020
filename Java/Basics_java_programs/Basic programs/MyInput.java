import java.util.Scanner;

public class MyInput {

    public static void main(String[] args) {
        
        System.out.println("Enter a number");

        Scanner sc = new Scanner(System.in);

        int x = sc.nextInt();
        sc.close();
        System.out.println("You have entered");

        System.out.println(x);

    }
    
}
