import java.util.*;
import java.lang.*;

class Permutation
{
static void CombinationRepetitionUtil(int chosen[], int arr[],
            int index, int r, int start, int end) {
        
        if (index == r) {
double value =0;
            for (int i = 0; i < r; i++) {

if(arr[chosen[i]]==1)
value+=4;
else if(arr[chosen[i]]==2)
value+=3;
else if(arr[chosen[i]]==3)
value+=2;
else
value+=1;
                System.out.printf("%d ", arr[chosen[i]]);
            }
             System.out.print(" = "+value/4);
            System.out.printf("\n");
            return;
        }
 
        
        for (int i = start; i <= end; i++) {
            chosen[index] = i;
            CombinationRepetitionUtil(chosen, arr, index + 1,
                    r, i, end);
        }
        return;
    }
 

    static void CombinationRepetition(int arr[], int n, int r) {
       
        int chosen[] = new int[r + 1];
 
       
        CombinationRepetitionUtil(chosen, arr, 0, r, 0, n - 1);
    }
 

    public static void main(String[] args) {
        int arr[] = {1, 2, 3, 4};
        int n = arr.length;
        int r = 4;
        CombinationRepetition(arr, n, r);
    }
    public int functionality(String s,int value)
    {
     
String c;
String A = "A",B="B",C="C";
     for(int i=0;i<s.length();i++){
      c= Character.toString(s.charAt(i));
	System.out.print(c+",");
      if(c.equals(A))
	value+=4;
      else if(c.equals(B))
	value+=2;
      else if(c.equals(C))
  	value-=2;
      else
	value-=4;
 
     }



	return value;
    }
 

}
