/*
Edit Distance
Given two strings s and t of lengths m and n respectively, find the edit distance between the strings.
Edit Distance
Edit Distance of two strings is minimum number of operations required to make one string equal to other. In order to do so you can perform any of 
the following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character

Note : Strings don't contain spaces

Input Format :
The first line of input contains a string, that denotes the value of s. The following line contains a string, that denotes the value of t.

Output Format :
The first and only line of output contains the edit distance value between the given strings.

Constraints :
1<= m,n <= 10

Time Limit: 1 second

Sample Input 1 :
abc
dc

Sample Output 1 :
2
*/

int editDistance(string s1, string s2) {
	// Write your code here
   	if(s1.length() == 0) {
        return s2.length();
    }
	
    if(s2.length() == 0) {
        return s1.length();
    }
    
    if(s1.back() == s2.back()) {
        s1.pop_back();
        s2.pop_back();
        return editDistance(s1, s2);
    }
   
    return 1 + min(editDistance(s1, string(s2.begin(), s2.end() - 1)),
                   min(editDistance(string(s1.begin(), s1.end() - 1), s2),
    		       editDistance(string(s1.begin(), s1.end() - 1), string(s2.begin(), s2.end() - 1)))
                  );
}
