import java.io.*;
import java.util.*;

public class Main {

public static void main(String[] args) throws Exception {
Scanner scn = new Scanner (System.in);
String s=scn.next();
printKPC(s, "");

}

static String[] code= {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};
public static void printKPC(String str, String asf) {

if(str.length()==0){
System.out.println(asf);
return;
}
char ch =str.charAt(0);
String rest= str.substring(1);
String codeforch= code[ch-'0'];
for(int i =0; i <codeforch.length(); i++){
char opt=codeforch.charAt(i);
printKPC(rest, asf+opt);

}



}

}
