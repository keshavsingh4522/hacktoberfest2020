package For_Loop;

public class Factorial {
    public static void main(String[] args) {
        
        int n = 5;
        int fact = 1;

        for (int i = n; i > 0; i--) {
            fact = fact * i;
        }
        System.out.println("Factorial of "+ n + " is: " + fact);
    }
}
