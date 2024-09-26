import java.util.*;
public class tower {
    static int count=0;
    public static int steps(int n,char a,char b,char c) {
        if (n == 1) {
            System.out.println("Move Disk from " + a + " to " + c);
            count++;
        } else {
            steps(n - 1, a, c, b);
            steps(1, a, b, c);
            steps(n - 1, b, a, c);
        }
        return count;
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the no.of disks");
        int n=sc.nextInt();
        int a=steps(n,'B','A','E');
        System.out.println("Total no.of moves= "+a);
    }
}
