package com.example;
import java.util.Scanner;
class Custom extends Exception  {

    public  Custom(String custom_exception)  {

        System.out.println(custom_exception );
    }
    public Custom() {

    }
    public String deepak() throws Custom {

        System.out.println("throws working    ");
        throw new Custom();

    }
//    public String customException(){
//        return "customException() called";
//    }
}
public class CustomException  {
    public static void main(String[] args)  {

//        int a;
//        Scanner sc = new Scanner(System.in);
//        a= sc.nextInt();
        Custom c = new Custom();

        try {
            c.deepak();
        } catch (Custom e) {
            System.out.println("exception working     " + e);

        }
//        if (a<273){
//            try{
//                throw new Custom("Custom Exception");
//
//            }
//            catch(Custom e){
//
//                System.out.println(e.customException());
//
//            }
//        }


    }

}
