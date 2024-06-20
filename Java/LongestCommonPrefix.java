import java.io.*;
import java.util.Scanner;

class LongestCommonPrefix{
      int n;
      /* Declare an instance variable to store the list of strings */
    String [] str;
  
      LongestCommonPrefix(String[] listOfStrings,int a){
        str= listOfStrings;
        n=a;
    }
  
      public String augment(String str1,String str2){
        String answer = "";
        int n1 = str1.length(), n2 = str2.length();
        int min= Math.min(n1,n2);
        for (int i = 0;i<min;i++) {
            if (str1.charAt(i) != str2.charAt(i)) {
                break;
            }
            answer += str1.charAt(i);
        }
 
        return (answer);
    }
  
      public String longestPrefixString(){
        String prefix = str[0];
 
        for (int i = 1; i <= n - 1; i++) {
            prefix = augment(prefix, str[i]);
        }
 
        return (prefix);  
    }
}

public class Solution{

    public static void main(String[] args) {
       Scanner scan = new Scanner(System.in);
       int n =scan.nextInt();
       String[] str = new String[n];
       for (int i = 0; i <str.length;i++){
           str[i]= scan.next();
       }
       LongestCommonPrefix obj = new LongestCommonPrefix(str,n);
       String answer=obj.longestPrefixString();
       if (answer.length() > 0) {
        System.out.println(answer);
        } else {
        System.out.println("-");
        }
       scan.close();
    }
}
