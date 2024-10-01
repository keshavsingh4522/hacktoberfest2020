// Java program to determine whether the number is
// Armstrong number or not
public class Armstrong
{
	/* Function to calculate x raised to the
	power y */
	int power(int x, long y)
	{
		if( y == 0)
			return 1;
		if (y%2 == 0)
			return power(x, y/2)*power(x, y/2);
		return x*power(x, y/2)*power(x, y/2);
	}

	/* Function to calculate order of the number */
	int order(int x)
	{
		int n = 0;
		while (x != 0)
		{
			n++;
			x = x/10;
		}
		return n;
	}

	// Function to check whether the given number is
	// Armstrong number or not
	boolean isArmstrong (int x)
	{
		// Calling order function
		int n = order(x);
		int temp=x, sum=0;
		while (temp!=0)
		{
			int r = temp%10;
			sum = sum + power(r,n);
			temp = temp/10;
		}

		// If satisfies Armstrong condition
		return (sum == x);
	}

	// Driver Program
	public static void main(String[] args)
	{
		Armstrong ob = new Armstrong();
		int x = 153;
		System.out.println(ob.isArmstrong(x));
		x = 1253;
		System.out.println(ob.isArmstrong(x));
	}
}
