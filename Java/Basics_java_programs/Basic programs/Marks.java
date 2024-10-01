import java.util.Scanner;

public class Marks {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        System.out.println("Please enter your CGPA out of 10: ");

        int cgpa = sc.nextInt();
        sc.close();
        
        if (cgpa > 10) {
            System.out.println("Please enter a valid cgpa!!");
        } else if (cgpa <= 3 && cgpa > 0) {
            System.out.println("You are Failed");
        } else if (cgpa > 3 && cgpa <= 5) {
            System.out.println("Boundary pass");
        } else {
            System.out.println("Pass with good marks");
        }
    }
}
