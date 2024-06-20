//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by FernFlower decompiler)
//

package com.company;

public class Guess_The_Number {
    public Guess_The_Number() {
    }

    public static void main(String[] args) {
        Game ram = new Game();
        System.out.println("So, let start the game");
        System.out.println("Enter the number between 1 and 100");
        ram.take_user_input();

        while(!ram.isCorrect()) {
            System.out.println("Guess another number");
            ram.take_user_input();
        }

        System.out.println("Hurrah! You guess the correct number in " + ram.no_of_guesses + " times");
    }
}
