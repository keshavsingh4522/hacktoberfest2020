import java.util.Scanner;

class Chammi{
    public static void main(String[]args){
        Scanner scan=new Scanner(System.in);
        
        System.out.print("input average : ");
        int x = scan.nextInt();
                
        if(x>75){
            System.out.println("A");
        }else if(x>65){
            System.out.println("B");
         }else if(x>55){
            System.out.println("C"); 
           }else if(x>35){
            System.out.println("S"); 
           
            
        }else{
			
            System.out.println("FAIL");    
        }
        

    }
}
