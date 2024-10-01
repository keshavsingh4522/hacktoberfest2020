package com.arraylist;


import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Scanner sc= new Scanner(System.in);
        System.out.println("ENTER THE SIZE OF ARRAY LIST");
        int size = sc.nextInt();
        ArrayList<Integer> array= new ArrayList<>();
        int temp;
        for(int i=0;i<size;i++){
            temp=sc.nextInt();
            array.add(temp);
        }

        boolean flag=true;
        while(flag){
            int n;
            System.out.println("which test " +
                    "1 add\n " +
                    "2 remove\n" +
                    "3: print\n" +
                    "4 clear array list\n" +
                    "5 exit\n" +
                    "6 copy array list\n" +
                    "7 print copy array list\n");
            n= sc.nextInt();
        switch (n) {
            case 1:
                System.out.println("element you want to add");
                int q= sc.nextInt();
            array.add(12);
            break;
            case 2:
                int k;
                System.out.println("enter index to remove");
                k=sc.nextInt();
                array.remove(k);
                break;
            case 3:
                System.out.println("print array list");
                for (int i=0;i< array.size();i++){
                    System.out.println( array.get(i));
                }
                break;
            case 4:
                array.clear();
                break;
            case 5:
                flag=false;
                break;
            case 6:
                ArrayList<Integer> copyarraylist=new ArrayList<>();
                copyarraylist=(ArrayList)array.clone();



                System.out.println("second array list");
                for (int i=0;i<copyarraylist.size();i++){
                    System.out.println(copyarraylist.get(i));
                }
                break;
        }



      }
    }
}
