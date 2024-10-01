import java.util.Scanner;

public class towerOfHanoi {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n= in.nextInt();
        int t1id= in.nextInt();
        int t2id= in.nextInt();
        int t3id= in.nextInt();
        toh(n,t1id,t2id,t3id);
    }
    static void toh(int n, int t1id , int t2id ,int t3id){
        if(n == 0){
            return;
        }
        toh(n-1 ,t1id, t3id, t2id);
        System.out.println(n +"[" + t1id + " -> " + t2id + "]");
        toh(n-1, t3id, t2id, t1id);
    }
}
