import java.util.Scanner;

public class HolloRombus {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter N : ");
        int count = sc.nextInt();
        System.out.print("Enter Symbol : ");

        char symbol = sc.next().charAt(0);

        int i = 1;
        int j;
        while ( i <= count ) {

            j = 1;
            while ( j++ <= count - i ) {
                System.out.print(" ");
            }
            if ( i == 1 || i == count ) {
                j = 1;
                while ( j <= count ) {
                    System.out.print(symbol);
                    j++;
                }
            } else {
                j = 1;
                while ( j <= count ) {
                    if ( j == 1 || j == count ) {
                        System.out.print(symbol);
                    } else {
                        System.out.print(" ");
                    }
                    j++;
                }
            }
            System.out.println();
            i++;
        }
    }

}
