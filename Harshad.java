public class Main {
    public static void main(String[] args)
	{
		//make a copy of original number
		int n = 47;
		//declare a variable to store sum of digits
		int result = 0;
		//perform logic for calculating sum of digits of a number
		while(n != 0)
		{
			int pick_last = n % 10;
			result = result + pick_last;
			n = n / 10;
		}
		/*use condition to check whether the number entered by  
		user is completely divisible by its sum of digits or not*/
      if(n % result == 0)
      System.out.println("Harshad Number");
          else
        System.out.println("Not a Harshad Number");
}
}
