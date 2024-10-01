package Strings;

import java.util.Arrays;
// anagram = chars of strings are same
public class Anagram {
	static boolean isAnagram_eff(String s1, String s2) {
		int [] count = new int[256];
		if(s1.length() != s2.length())	return false;
		for(int i=0; i<s1.length(); i++) {
			count[s1.charAt(i)]++;
			count[s2.charAt(i)]--;
		}
		for(int i=0;i<256;i++) {
			if(count[i]!=0)	return false;
		}
		return true;
	}
	
	public static void main(String[] args) {
		String s1 = "listen";
		String s2 = "silent";
		System.out.println(isAnagram_eff(s1,s2));

	}
	
	static boolean isAnagram_Naive(String s1, String s2) {
		if(s1.length() != s2.length())
			return false;
		char [] c1 = s1.toCharArray();
		Arrays.sort(c1);
		s1 = new String(c1);
		
		char[] c2 = s2.toCharArray();
		Arrays.sort(c2);
		s2 = new String(c2);
		
		return s1.equals(s2);
	}
}
