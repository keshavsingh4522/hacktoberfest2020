public class PalindromeNumber
{             
public static void main(String[] args)
{
               int no = 535; // To be checked for palindorme
               int tempVar = no; 
               int sum = 0;
               while(no > 0)
               {
                               // reversing the number
                               sum = sum * 10;
                               sum = sum + (no % 10);
                               no = no / 10;
               }
               if(tempVar == sum)
                               System.out.print("The number " + tempVar +" is a palindrome number.");
               else
                               System.out.print("The number " + tempVar +" is not a palindrome number.");
}
}
