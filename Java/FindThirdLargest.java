public class FindThirdLargest{  
public static int getThirdLargest(int[] a, int total){  
int temp;  
for (int i = 0; i < total; i++)   
        {  
            for (int j = i + 1; j < total; j++)   
            {  
                if (a[i] > a[j])   
                {  
                    temp = a[i];  
                    a[i] = a[j];  
                    a[j] = temp;  
                }  
            }  
        }  
       return a[total-3];  
}  
public static void main(String args[]){  
int a[]={2,5,6,3,20,77};  
int b[]={33,55,77,12,4,78,9,43,33};  
System.out.println("Third Largest: "+getThirdLargest(a,6));  
System.out.println("Third Largest: "+getThirdLargest(b,9));  
}}  
