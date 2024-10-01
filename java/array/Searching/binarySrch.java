import javax.lang.model.util.ElementScanner14;
import javax.net.ssl.HandshakeCompletedListener;

public class binarySrch {
    public static void main(String args[]) {
        int arr[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
        int key = 70;
        int li = 0;
        int hi = arr.length;
        int mi = (li + hi) / 2;
        while (li <= hi) {
            if (arr[mi] == key) {
                System.out.println("the element is int the index " + mi + " position ");
                break;
            }
            else if (arr[mi] < key) {
                li = mi + 1;
            } else {
                hi = mi - 1;
            }
            mi = (li + hi) / 2;
        }
    }
}