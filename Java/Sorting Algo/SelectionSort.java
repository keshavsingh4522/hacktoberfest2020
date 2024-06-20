import java.util.*;
public class Selection_Sort 
{  
    public static void selectionSort(int[] arr)
    {  
        for (int i = 0; i < arr.length - 1; i++)  
        {  
            int index = i;  
            for (int j = i + 1; j < arr.length; j++)
            {  
                if (arr[j] < arr[index])
                {  
                    index = j; 
                }  
            }  
            //swapping
            int smallerNumber = arr[index];   
            arr[index] = arr[i];  
            arr[i] = smallerNumber;  
        }  
    }  
       
    public static void main(String a[])//Main
    {  
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int arr1[] = new int[n];
        System.out.println("Enter elements of array");
        for(int i=0;i<n;i++)
        {
            arr1[i] = sc.nextInt();
        }
        System.out.println("Array elements before Selection Sort");  
        for(int i:arr1)
        {  
            System.out.print(i+" ");  
        }  
        System.out.println();  
          
        selectionSort(arr1); //sorting array using selection sort  
         
        System.out.println("Array Elemnets after Selection Sort");  
        for(int i:arr1)
        {  
            System.out.print(i+" ");  
        }  
    }  
}  
