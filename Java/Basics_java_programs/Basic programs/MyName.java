import java.util.Scanner;

public class MyName {
    public static void main(String[] args) {
        
        Scanner scan = new Scanner(System.in);

        System.out.println("Enter your name");
        String name =  scan.nextLine();

        System.out.println("Enter your age" );
        Integer age = scan.nextInt();
        scan.close();

        System.out.println("Hello My name is " + name);
        System.out.println("And my age is " + age);

    
    }
    
}
