package com.company;
import java.util.Random;
import java.util.Scanner;
class Game{
    public int number;
    public int input;
    public int getNoOfGuesses;


    public int getGetNoOfGuesses() {
        return getNoOfGuesses;
    }

    public void setGetNoOfGuesses(int getNoOfGuesses) {
        this.getNoOfGuesses = getNoOfGuesses;
    }

    Game(){
        Random rand = new Random();
        this.number=rand.nextInt(100);
    }
    void takeUserInput(){
        System.out.println("GUESS THE NUMBER: ");
         Scanner sc= new Scanner(System.in);
        input = sc.nextInt();
    }
    boolean isCorrectNumber(){
        getNoOfGuesses++;
        if(input==number){
            System.out.format("YEAH YOU GUESSED IT RIGHT IT WAS %d IN %d ATTEMPTS ",number,getNoOfGuesses);
            return true;
        }
        else if(input<number){
            System.out.println("GUESS A HIGH NUMBER...");
        }
        else if(input>number){
            System.out.println("GUESS A LOWER NUMBER...");
        }
            return false;
    }

}

public class guess_number {
    public static void main(String[] args) {

        Game g = new Game();
        boolean b=false;
        while(!b) {
            g.takeUserInput();
            b = g.isCorrectNumber();

        }
    }
}
