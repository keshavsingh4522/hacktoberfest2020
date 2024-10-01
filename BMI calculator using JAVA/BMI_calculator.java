//Java program to calculate the BMI

//Importing the Scanner package
import java.util.Scanner;

//Main / Drived Class
public class Main
{
    //Main Function
    public static void main(String[] args) {
        //Creating the object of Scanner Class
        Scanner input = new Scanner(System.in);
        //Giving the hint to user what has to enter
        System.out.println("Enter your weight unit (kg or lbs): ");
        //Taking Weight Unit from user
        String unit = input.nextLine();
        //Giving the hint to user what has to enter
        System.out.println("Enter your Weight : ");
        //Taking weight from user
        double weight = input.nextDouble();

        double height = 0;
        //Checking which weight unit has been selected by user
        if(unit.equals("kg")){
            //If unit is kg
            //Giving the hint to user what has to enter
            System.out.println("Enter your Height(In Meters) : ");
            //Taking height(in Meters) from user
            height = input.nextDouble();
        }else if(unit.equals("lbs")){
            //Giving the hint to user what has to enter
            System.out.println("Enter your Height(In Inches) : ");
            //Taking height(in Inches) from user
            height = input.nextDouble();
        }
        //Declaring a double type parameter
        double bmi;
        /*Switch Cases on weight units because BMI Formula changes according to
        /* the Weight Units
        */
        switch (unit){
            //If unit is kg
            case "kg":
                //caluclate the bmi with formula and store it in variable
                bmi = weight / (height * height);
                //print the BMI
                System.out.println("YOUR BMI IS : "+ bmi +" kg/m2");
                break;
            //If unit is lbs
            case "lbs":
                //caluclate the bmi with formula and store it in variable
                bmi = 703 * (weight / (height * height));
                //print the BMI
                System.out.println("YOUR BMI IS : "+ bmi +" lbs/in2");
                break;
            default:
                System.out.println("Please choose correct weight unit");
        }
    }
} 
