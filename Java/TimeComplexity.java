import java.util.*;
import java.io.*;
import java.lang.*;
import java.util.Arrays; 
/**
 * Write a description of class TimeComplexity here.
 *
 * @author (Oarabile Mwiya)

 */
public class TimeComplexity {

    private static int[] integers;

    private static int[] integer;
    private static Scanner input;
    private static Scanner inputs;

    public static void main(String [] args) throws IOException {
        Random numbers = new Random();  
        File file = new File("numbers.txt");
        try{
            PrintWriter output = new PrintWriter(file);
            for(int counter = 1; counter <= 1000; counter++){
                int number = numbers.nextInt(1000) + 1;
                output.println(number);}
            output.close();
        }catch (IOException ex){
            System.out.printf("ERROR: %s\n",ex);
        }
       
        BubbleTime() ;
        
        
    }

    public static void Array100() throws IOException{
        FileReader file1 = new FileReader("numbers.txt");
        integers = new int[100];
        input = new Scanner(file1);
        int i = 0; 
        while(i<integers.length )
        {
            integers[i] = input.nextInt();
            i++;

        }
        System.out.println("Arrays with 100 integers");
        System.out.println();
        for(int array100 : integers){

            bubbleSort(integers);

            System.out.print(array100 +",");
        }

    }

    public static void Array200() throws IOException{
        FileReader file1 = new FileReader("numbers.txt");
        integer = new int[200];
        inputs = new Scanner(file1);
        int i = 0;
        while(i<integer.length )
        {
            integer[i] = integer[i] + inputs.nextInt();
            i++;

        }
        System.out.println("Arrays with 200 integers");
        System.out.println();

        for(int array200 : integer){
            sort(integer);
            System.out.print(array200+ ",");
        }
    }

    public static void Array300() throws IOException{
        FileReader file1 = new FileReader("numbers.txt");
        integers = new int[300];
        input = new Scanner(file1);
        int i = 0; 
        while(i<integers.length )
        {
            integers[i] = input.nextInt();
            i++;

        }
        System.out.println("Arrays with 300 integers");
        System.out.println();
        for(int array100 : integers){
            System.out.print(array100 +",");
        }

    }
    
    public static void BubbleTime() throws IOException{
     int n = 0;
        while(n < 3){
        long start = System.currentTimeMillis();
        TimeComplexity.Array100();
        long time = System.currentTimeMillis() - start;
       System.out.println("\nBubble Time:"+ time+"ms");
    n++;
    }
    
    }
    
    public static void InsertionTime() throws IOException{
        
             int n = 0;
        while(n < 3){
        long start = System.currentTimeMillis();
        TimeComplexity.Array100();
        long time = System.currentTimeMillis() - start;
       System.out.println("\nInsertion Time:"+ time+"ms");
    n++;
    }
    }

    static void bubbleSort(int arr[]) 
    { 

        int n = arr.length; 
        for (int i = 0; i < n-1; i++) 
            for (int j = 0; j < n-i-1; j++) 
                if (arr[j] > arr[j+1]) 
                { 
                    // swap arr[j+1] and arr[i] 
                    int temp = arr[j]; 
                    arr[j] = arr[j+1]; 
                    arr[j+1] = temp; 
                }

    }

    /*Function to sort array using insertion sort*/
    static void sort(int arr[]) 
    { 
        int n = arr.length; 
        for (int i = 1; i < n; ++i) { 
            int key = arr[i]; 
            int j = i - 1; 

            /* Move elements of arr[0..i-1], that are 
            greater than key, to one position ahead 
            of their current position */
            while (j >= 0 && arr[j] > key) { 
                arr[j + 1] = arr[j]; 
                j = j - 1; 
            } 
            arr[j + 1] = key; 
        } 
    } 


}
