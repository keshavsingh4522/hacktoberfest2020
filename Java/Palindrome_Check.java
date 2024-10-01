/* By Tushar Sinha */

import java.util.*;

public class First {

    public static boolean isPalindrome(int x) {
        if(x < 0) return false;

        int save = x;
        int rev = 0;

        while(x != 0)
        {   rev = rev*10 + x%10;
            x /= 10;
        }

        if(save == rev) return true;
        return false;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter any number : ");
        int num = sc.nextInt();

        if(isPalindrome(num)) System.out.println("\nYes!");
        else System.out.println("\nNo!");

        sc.close();
    }
}
