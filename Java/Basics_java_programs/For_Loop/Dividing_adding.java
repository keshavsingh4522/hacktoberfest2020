package For_Loop;

import java.util.Scanner;

public class Dividing_adding {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter any number");
        int n = sc.nextInt();
        sc.close();

        float result = 0;

        for (float i = 1; i <= n; i++) {

            if (i % 2 == 0) {

                result -= 1 / i ;
            } else {

                result += 1 / i ;
            }
        }

        System.out.println(result);

    }
}
