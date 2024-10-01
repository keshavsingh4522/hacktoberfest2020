
import java.util.*;

public class lockerPuzzle{
	public static void main(String[] args){
		boolean[] lockers = new boolean[101];
		
		//Initially opening all the lockers which are multiples of 1 before moving onto 2
		for (int  i= 1; i < lockers.length; i++)
			lockers[i] = true;
		
	    //Closing the locker if it is open, and opening the locker if it is closed 
		for (int i = 2; i <= 100; i++){
			for (int j = 1; i * j <= 100; j++){
				if(lockers[i * j] == true)
					lockers[i * j] = false;
				else
					lockers[i * j] = true;
			}
		}
		//Displaying the open Lockers
		for (int i = 0; i < lockers.length; i++){
			if (lockers[i] == true)
				System.out.println("Locker " + i + " is open");
		}
	}
}
