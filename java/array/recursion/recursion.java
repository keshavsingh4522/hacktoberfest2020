public class recursion{
    public static void prinfun(int n){
        if (n == 10){
            System.out.println(n);
            return;
        }
        prinfun(n+1);
        System.out.println(n);
    }
    public static void main (String args[]){
        prinfun(10);
    }
}