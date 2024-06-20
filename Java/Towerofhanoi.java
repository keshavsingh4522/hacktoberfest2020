public class Towerofhanoi {
    public static void main(String[] args) {
        int n=3;
        char A='A',B='B',C='C';
        TOH(n,'A','B','C');
      
    }
    public static void TOH(int n,char A,char B,char C)
    {
        if(n==1)
        {
        System.out.println("Move disc "+n+" from "+A+"to "+C);
        return ;
        }
        else{
        TOH(n-1,A,C,B);
        System.out.println("Move disc "+n+" from"+A+"to "+C);
        TOH(n-1,B,C,A);
        }
        
        }

    }
    
