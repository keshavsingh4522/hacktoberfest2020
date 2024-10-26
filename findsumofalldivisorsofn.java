// Formula based Java program to
import java.util.*;
import java.lang.*;

public class GfG {

	// Returns sum of all factors of n.
	public static int sumofFactors(int n)
	{
		// If n is odd, then there
		// are no even factors.
		if (n % 2 != 0)
			return 0;

		// Traversing through all prime
		// factors.
		int res = 1;
		for (int i = 2; i <= Math.sqrt(n); i++) {
			int count = 0, curr_sum = 1;
			int curr_term = 1;

			// While i divides n, print i and
			// divide n
			while (n % i == 0) {
				count++;

				n = n / i;

				// here we remove the 2^0 that
				// is 1. All other factors
				if (i == 2 && count == 1)
					curr_sum = 0;

				curr_term *= i;
				curr_sum += curr_term;
			}

			res *= curr_sum;
		}

		// This condition is to handle the
		// case when n is a prime number.
		if (n >= 2)
			res *= (1 + n);

		return res;
	}

	// Driver function
	public static void main(String argc[])
	{
		int n = 18;
		System.out.println(sumofFactors(n));
	}
}

/* This code is contributed by Sagar Shukla */
