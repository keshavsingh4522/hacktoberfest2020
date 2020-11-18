
/**
 * Write a description of class Main here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
import java.io.*;
import java.util.*;
public class Main
{
    static DoublyLinkedList dll= new DoublyLinkedList();
    public static  void readFile(String fileName){
        try{
            Scanner sc= new Scanner(new File( fileName));
            while(sc.hasNextLine()){
                String word= sc.nextLine();
                if(!word.isEmpty()){
                    String[] villages=word.split("\\s++");
                    //dll.addNodeToEnd(villages[1]);
                    dll.addNodeToFront(villages[0+1]);
               }
            }
        }
        catch(Exception e){
            System.out.println("File Not Read");
        }
    }

    public static void main(String[] args)throws IOException{
        readFile("villages.txt");
        dll.printNodes();
        /*for(int i=0; i<=15; i++){
            dll.deleteLastNode();
           dll.printNodes();
        }
        System.out.println("***********new list****************");
        dll.printNodes();*/
        System.out.println("***********new list****************");
        //dll.addNodeBefore("shoshong","gaborone");
        dll.printNodes();
        System.out.println("***********new list****************");
        dll.deleteNodeBefore("franscistown","gaborone");
        dll.printNodes();
    }
    
}
