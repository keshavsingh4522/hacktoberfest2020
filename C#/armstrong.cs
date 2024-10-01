using System;

public class ArmstrongChecker
{
	public static void Main(string[] args)
	{
		int n, r, sum = 0, temp;
		Console.Write("Enter the Number= ");
		n = int.Parse(Console.ReadLine());
		temp = n;
		while (n > 0)
		{
			r = n % 10;
			sum = sum + (r * r * r);
			n = n / 10;
		}

		if (temp == sum)
			Console.Write("It is an armstrong number.");
		else
			Console.Write("It is not an armstrong number.");
	}
}
// HAPPY HACKTOBER!
