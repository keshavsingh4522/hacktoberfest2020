/*
     Write a program to check whether entered number is armstrong or not.
     
     
     # WHAT IS ARMSTRONG NUMBER?
     In numerical number theory, the Armstrong number definition is the number in any given number base, which forms the total of the same number, 
     when each of its digits is raised to the power of the number of digits in the number.
*/


import java.lang.Math;
import java.util.*;

class ArmstrongNumber
{
    public static void main(String args[ ])
    {
       Scanner sc=new Scanner(System.in);
       
       int n=sc.nextInt();  // Enter a number which is to be checked
       
       int temp=n,sum=0,d,p=String.valueOf(n).length();

       while(n>0)
       {
          d=n%10;
          sum+=Math.pow(d,p);
          n=n/10;
        }

      if(sum==temp)
      {
         System.out.println("Entered number is armstrong");
      }
      else
      {
         System.out.println("Entered number is not armstrong");
      }
   }
}

