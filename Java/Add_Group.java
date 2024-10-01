import java.util.Scanner;

public class Add_Group {
    static Scanner input = new Scanner(System.in);
    
    public static void main(String [] args){
        add();
    }

    public static void add() {
        System.out.println("How may numbers would you like to add?");
        
        //  The number variable takes an input of type int from the user        
        int number = input.nextInt();
        
        //  The numArray variable holds an array of integers, the size of the array depends on the value stored in the number 
        //  variable. 
        int numArray[] = new int[number];
        
        //  The sum variable will hold the sum of all the values in numArray and it is initially assigned to zero
        int sum = 0;
        
        //  For each iteration of the loop:
        //  1: a number is taken from the user and stored in the array
        //  2: the number is added to sum
        for(int i = 0; i < number; i++) {
            System.out.println("Enter number " + (i + 1));
            numArray[i] = input.nextInt();
            sum = sum + numArray[i];
        }
        
        System.out.println("Sum of the numbers is " + sum);
    }
}
