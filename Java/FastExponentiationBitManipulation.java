public class FastExponentiationBitManipulation {

    //to calculate a^n
    public static int pow(int a, int n) {
        int ans = 1;

        while(n > 0) {
            if((n&1) != 0) { //checking bit is 0 or 1
                ans = ans * a;
            }
            a = a*a;
            n = n>>1;
        }

        return ans;
    }
    public static void main(String args[]) {
        System.out.println(pow(1024,1024));  
     }
}
