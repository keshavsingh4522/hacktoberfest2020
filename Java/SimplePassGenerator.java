package ParkingExamen;

import javax.swing.*;

public class SimplePassGenerator {
    public static void main(String arg[]){
        int number = Integer.parseInt(JOptionPane.showInputDialog(null,"Introduce the number enter one number of characters"));
        String pass="";

        for (int i = 0 ; i<number; i++){
            int x = (int) Math.floor(Math.random()*(122-48+1)+48);
            char ch = (char) x;
            pass += ch ;
        }

        JOptionPane.showMessageDialog(null, "Your passwor is:\n" + pass, "Pass Generator", JOptionPane.INFORMATION_MESSAGE, null);
    }
}
