import java.lang.*;
import java.util.*;

public class Program
{
    public static void main(String[] args) {
        
        
        
       int arr[]={1,2,3,4,5,6};
        
        int chg = arr[0];
        
        for(int i=0;i<arr.length-1;i++)
        {
          
            arr[i]=arr[i+1];
        }
        arr[arr.length -1]= chg;
        
        for(int i=0;i<arr.length;i++)
        {
            System.out.println(arr[i]);
        }
        
    }
}
