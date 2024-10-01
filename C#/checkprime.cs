using System;  
  public class SumExample  
   {  
     public static void Main(string[] args)  
      {  
       int  n,sum=0,m;         
       Console.Write("Enter a number: ");      
       n= int.Parse(Console.ReadLine());     
       while(n>0)      
       {      
        m=n%10;      
        sum=sum+m;      
        n=n/10;      
       }      
       Console.Write("Sum is= "+sum);       
     }  
  }  
