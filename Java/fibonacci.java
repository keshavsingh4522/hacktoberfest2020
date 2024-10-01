import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	// write your code here
        System.out.println("Enter the number : ");
        Scanner scan = new Scanner(System.in);
        int limit = scan.nextInt();
        System.out.println("Enter the first number : ");
        int first_num = scan.nextInt();
        System.out.println("Enter the second number : ");
        int second_num = scan.nextInt();
        int next_num = 0;
        //int i = 0;
        for (int i=1;i<=limit;i++){
            System.out.print(first_num+", ");
            next_num = first_num + second_num;
            first_num = second_num;
            second_num = next_num;
        }
        scan.close();
    }
}
