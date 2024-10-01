import java.io.*;
import java.util.*;

class Card{
 String name = "John Doe"; // card holder's name
  
   int credits = 10;
    
   static void welcome(){
      System.out.println("Hi, Card management in process...");  
    }
  
   public String toString(){
      System.out.println("This card belongs to" + name);
        return "";
    }
}

class SilverCard extends Card{
 SilverCard(int amountPaid){
      /*  Implement the constructor to add additional credits for the card based on the 
         amount paid.
         Rs. 1000 - 1999 -> 5 additional credits
         Rs. 2000 - 3999 -> 10 additional credits
         Rs. 4000 - 9999 -> 15 additional credits
         More than Rs. 10000 -> 20 additional credits
         */
        if(amountPaid >= 1000 && amountPaid <= 1999)this.credits = 5;
        else if(amountPaid >= 2000 && amountPaid <= 3999)this.credits = 10;
        else if(amountPaid >= 4000 && amountPaid <= 9999)this.credits = 15;
        else if(amountPaid >= 10000)this.credits = 20;
        
    }
  
    /*
     Create an overriden method for toString() to print the credits left in the card 
        along with the card holder's name.
    */
    public String toString(){
        System.out.println("Credits left in the card: " + this.credits);
        System.out.println("This card belongs to " + this.name);
        return "";
    }
  
   void deduct(int creditsSpent){
       /*  
         Instructions:
            
            1. If the number of credits spent is less than or equal to the number of credits left, 
             then proceed with the transaction and do the appropriate updations.
            2. Else, print an error message saying "Insufficient balance".
        */
        if(credits >= creditsSpent)credits -= creditsSpent;
        else System.out.println("Insufficient balance");
    }
}

class GoldCard extends SilverCard{
    final int FREE_CREDITS = 10;
    
    GoldCard(int amountPaid){
     /*
         Implement this constructor using the parent constructor with the additional free 
        Also use the free credits to increase your initial credits.
        */
        super(amountPaid);
        this.credits += FREE_CREDITS;
    }
   
   /*
     Implement a PRIVATE top-up method to add some credits to the account by paying Rs. 500
        for each top-up. Each top-up adds 5 credits to the card. Also show the number of credits    remaining in the card after the top-up.
    */
    private void topUp(){
        this.credits += 5;
        System.out.println("Credits left in the card: " + this.credits);
    }
  
   
   /* 
     Override the deduct method to decuct credits according to the following logic:
    
       1. If the number of credits spent is less than or equal to the number of credits left,
          then proceed with the transaction and do the appropriate updations.
       2. Else, top-up the the credits in the account using the top-up method implemented above.
    */
    void  deduct(int creditsSpent){
        if(credits >= creditsSpent)credits -= creditsSpent;
        else{
            topUp();
            deduct(creditsSpent);
        }
    }
}

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String type = sc.nextLine();
        String[] arr = type.split(" " , 0);
        type = arr[0];
        int r = Integer.parseInt(arr[1]);
        
        SilverCard card;
        if(type.equals("Silver"))card = new SilverCard(r);
        else card = new GoldCard(r);
        int nm= sc.nextInt();
        for(int i = 0; i < nm; ++i){
            int k = sc.nextInt();
            if(k == 1)card.toString();
            else {
                int c = sc.nextInt();
                card.deduct(c);
     }
}
    }
}
