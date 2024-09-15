import java.util.*;
public class ReverseString {
 
	public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);  
        System.out.print("Enter a string:\n");  
        String str= sc.nextLine();
		String reversed = reverseString(str);
		System.out.println("The reversed string is:\n" + reversed);
		
	}
	public static String reverseString(String str)
	{
		if (str.isEmpty()){
		 return str;
		}
		return reverseString(str.substring(1)) + str.charAt(0);
	}
 
}
