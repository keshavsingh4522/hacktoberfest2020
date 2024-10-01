import java.util.Scanner;

public class SwitchFruit {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        String fruit = input.next();

        switch (fruit) {
            case "mango" -> System.out.println("King of fruit");
            case "Apple" -> System.out.println("A sweet red fruit");
            case "Orange" -> System.out.println("Round fruit");
            case "Grapes" -> System.out.println("Small fruit");
            default -> System.out.println("Please enter a valid fruit");
        }
    }
}
