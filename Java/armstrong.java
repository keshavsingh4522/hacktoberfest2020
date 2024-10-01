import java.util.*;
public class DigitToString {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int r,sum=0;
		int n1 = n;
		while(n!=0) {
			r = n%10;
			sum+=Math.pow(r, 3);
			n/=10;
		}
		
		if(sum==n1)
			System.out.println("Its armstrong");
		else
			System.out.println("Its not");
		
	}
	
	
}
