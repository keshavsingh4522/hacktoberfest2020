import java.util.Scanner;
class Factorial
{  
 public static void main(String args[])
 {  
   Scanner sc = new Scanner(Syatem.in);
   System.out.println("Enter the Number ");
   int number =sc.nextInt();
  int i, fact =1;  
  for(i=1;i<=number;i++)
  {    
      fact=fact*i;    
  }    
  System.out.println("Factorial of "+number+" is: "+fact);    
 }  
}  
