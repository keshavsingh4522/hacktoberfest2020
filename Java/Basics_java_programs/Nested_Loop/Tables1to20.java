package Basics_java_programs.Nested_Loop;

public class Tables1to20 {
    
    public static void main(String[] args) {
        
        int x = 1;

        int result = 1;

        for (int j = 1; j <= 20; j++) {

            for (int i = 1; i <= 10; i++) {

                result = x * i;

                System.out.print(result + " ");
            }

            System.out.println();
            x += 1;
        }

    }
}