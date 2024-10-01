// leetcode question

//https://leetcode.com/problems/roman-to-integer/

public class roamnToInteger {
    public static void main(String[] args) {
       
                int I =1;
                int V =5;
                int X =10;
                int L =50;
                int C =100;
                int D =500;
                int M =1000;
                int res;
                for(int i=0; i<s.length()-1; i++){
                    if(s.charAt(i) == 'I'&& (s.charAt(i+1) == 'X' ||s.charAt(i+1) == 'X') ||
                     s.charAt(i) == 'X'&& (s.charAt(i+1) == 'L'||s.charAt(i+1) == 'C')||
                     s.charAt(i) == 'C'&& (s.charAt(i+1) == 'D'||s.charAt(i+1) == 'M')){
                     
                      res =  s.charAt(i+1) - s.charAt(i);
                    }
                }
            }
        }

