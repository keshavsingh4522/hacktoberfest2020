import java.util.Scanner;
public class Atm
{
	public static void main(String args[])throws IOException
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("                                                                    Hello! This is Money Withdrawl Service");
		System.out.println("\n");
		System.out.println("------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
		System.out.println("\n");
		System.out.println("                                                               If You Want to Proceed Press 1 For Exit Press 0");
		int a=sc.nextInt();
		if(a==0)
		{
	    System.out.println("                                                                              Have A Gud Day");
		}
		else
		{
			if(a==1)
			{
			System.out.println("                                              If Your Account is Already Created,Then Press 1 For Amount Withdrawl Press 0");
			int b=sc.nextInt();
			if(b==1)
			{
				System.out.println("                                                                Enter The Withdrawl Amount");
				int wam=sc.nextInt();
			}
			else
			{ 
				System.out.println("                                       To Create Account You Have To Insert Some Confidential Information");
				System.out.println("\n");
				System.out.println("\n");                   
				System.out.println("                                                              Proceed for 1 Exit for 0");
                int c=sc.nextInt();
				if(c!=0)
				{
					System.out.println("                                                         Thank You for Visiting Us");
				}
				else
				{
					System.out.println("                             Enter Your Official Name");
					System.out.println("\n");
					System.out.println("\n");
					String name=sc.next();
		            System.out.println("                                                Enter Your Aadhar Card Number(16 Digits)");
		            long adhar=sc.nextLong();
		            int count=0;
		            while(adhar != 0)
        {
            adhar /= 10;
            count++;
        }
		                if(count!=16)
                        {
                        	System.out.println("                      You Entered Wrong Aadhar Card Number. Restart The Process");
                        }
                        else
                        {
                        	System.out.println("                                  Enter Your Date Of Birth(ex-mm/dd/yyyyy)");
                        	int month=sc.nextInt();
                        	if(month>12)
                        	{
                        		System.out.println("                                         Invalid Month");
                                System.out.println("\n");
                                System.out.println("\n");
                                System.out.println("\n"); 
                        		System.out.println("                             Now! You Have To Restart The Process");
                        	}
                        	else
                            {
                        	int date=sc.nextInt();
                        	if(((month==1||month==3||month==5||month==7||month==9||month==10||month==12)&& (date<=31)) ||((month==2) && (date<=28)) ||((month==4||month==6||month==9||month==11)) && (date<=30))
                        	{
                        	int year=sc.nextInt();
                        	if((year>=1950)&&(year<=2015))
                        	{
                        		System.out.println("                                   How Much Money You Want to Deposite");
                        		long Depmoney=sc.nextLong();
                                System.out.println("\n");
                        		System.out.println("                                  Thanks For Creating Account In Our Service");
                        		}
                        	else
                        	{
                        		System.out.println("                                      Year Must Between in 1950 And 2015");
                        	}
                        }
                        else
                        {
                        	System.out.println("                                                     Invalid Date");
                            System.out.println("\n");
                            System.out.println("\n");
                            System.out.println("\n");
                        	System.out.println("                                       Now! You Have To Restart The Process");
                        }
                        }
}
        
				}
			}

		}
	}

}
