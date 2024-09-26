import java.util.*;  
public class BouncyNumberExample1  
{  
public static void main(String args[])   
{  
Scanner scan = new Scanner(System.in);  
System.out.print("Enter any number you want to check: ");  
//reading an integer from the user  
int inputNumber = scan.nextInt();  
//if any of the following condition returns true, the number id not bouncy   
if (isIncreasing(inputNumber) || isDecreasing(inputNumber) || inputNumber < 101)  
//prints if the number is not bouncy  
System.out.println(inputNumber+" not a bouncy number.");  
else  
//prints if the number is bouncy  
System.out.println(inputNumber+" is a bouncy number.");  
}  
//function that checks if the number is an increasing number or not  
public static boolean isIncreasing(int inputNumber)   
{  
//converts the number into string  
String str = Integer.toString(inputNumber);  
char digit;  
//flag set to true  
boolean flag = true;  
//iterates over the string up to length-1  
for(int i=0;i < str.length()-1;i++)   
{  
digit = str.charAt(i);  
//if any digit is greater than check next digit, it will not check further  
if(digit > str.charAt(i+1))   
{  
//flag set to false if the condition returns true     
flag = false;  
break;  
}      
}  
return flag;  
}  
//function that checks if the number is a decreasing number or not  
public static boolean isDecreasing(int inputNumber)   
{  
//converts the number into string  
String str = Integer.toString(inputNumber);  
char digit;  
//flag set to true  
boolean flag = true;  
//iterates over the string up to length-1  
for(int i=0;i < str.length()-1;i++)   
{  
digit = str.charAt(i);  
//if any digit is less than the next digit, it will not check further  
if(digit < str.charAt(i+1))   
{  
//flag set to false if the condition returns true     
flag = false;  
break;  
}      
}  
return flag;          
}  
}