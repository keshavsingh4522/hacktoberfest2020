package Arrays;

import java.util.Scanner;

public class MatricsAddition {
   
    public static void main(String[] args) {
        

        Scanner sc = new Scanner(System.in);

        int rows = sc.nextInt();
        int columns = sc.nextInt();
        sc.close();
    

        int a[][] = new int[rows][columns];
        int b[][] = new int[rows][columns];

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < columns; j++) {

                a[i][j] = sc.nextInt();
            }
        }
        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < columns; j++) {

                b[i][j] = sc.nextInt();
            }
        }


    }
}
