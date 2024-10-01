import java.util.Scanner;
import java.util.Random;

public class Main
{
    public static void main(String[] args) {
        Scanner scanner  = new Scanner(System.in);
        System.out.println("Welcome to Wonderland ! ");
        System.out.println("May I have your name ? ");
        String name = scanner.next();
        System.out.println("Hello " + name);

        System.out.println("Shall we begin the game ? ");
        System.out.println("\t1. Yes");
        System.out.println("\t2. No");

        int begin = scanner.nextInt();

        while(begin!=1){
            System.out.println("Shall we begin the game ? ");
            System.out.println("\t1. Yes");
            System.out.println("\t2. No");

            begin = scanner.nextInt();
        }

        Random random = new Random();
        int tries = 0;
        System.out.println("Guess a Number - ");
        while(tries<5){
            tries++;

            int number = scanner.nextInt();

            if(number < random.nextInt()){
                System.out.println("Guess higher number");
            }
            else if(number > random.nextInt()){
                System.out.println("Guess lower number");
            }
            else{
                System.out.println("You won the Game");
                break;
            }

        }

        System.out.println("Game Over ! ");


    }
}
