package com.company;

import java.util.ArrayList;

public class Pangram {
    public static void main(String[] args) {
        String sentence = "abcdefghijklmnopqrstuvwxyz";
        System.out.println(checkIfPangram(sentence));
    }
    static boolean checkIfPangram(String sequence){
        if(sequence.length()<26){
            return false;
        }
       int []count = new int[256];
        for (int i = 0; i < sequence.length(); i++) {
            count[sequence.charAt(i)]++;
        }
        for (int i = 97; i <= 122; i++) {
            if(count[i]==0){
                return false;
            }

        }
        return true;

    }
}
