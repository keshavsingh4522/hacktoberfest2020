package Arrays;

import java.util.Scanner;

public class AverageMarksOfStudents {

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of students: ");
        int n = sc.nextInt();

        int marks[] = new int[n];
        int total = 0;
        int average = 0;

        System.out.println("Enter the Marks of "+ n +" students");
        for (int i = 0; i < marks.length; i++) {

            marks[i] = sc.nextInt();
            total += marks[i];
        }
        sc.close();
        average = total/n ;

        System.out.println("Total of all " + n + " marks are: " + total);
        System.out.println("Average of all " + n + " marks are: " + average);

    }
}