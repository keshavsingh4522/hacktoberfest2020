??import java.util.*;
public class DutchNationalFlag{
    public void main()
    {
        Scanner Sc = new Scanner(System.in);
        System.out.println("Enter the Size and Elements");
        int n = Sc.nextInt();
        int a[] = new int[n];
        for(int i = 0; i< a.length;i++)
        {
            a[i] = Sc.nextInt();
        }
        int low = 0, mid = 0;
        int high = a.length-1;
        while(mid<=high)
        {
            switch(a[mid])
                {
                case 0: 
                {
                    int temp = a[low];
                     a[low] = a[mid];
                     a[mid] = temp;
                    mid++;
                    low++;
                    break;
                }
                case 1:
                mid++;
                break; 
                
                case 2:
                {
                    int temp = a[mid];
                     a[mid] = a[high];
                     a[high] = temp;
                    
                   high--;
                   break;
                }
            
        
            }
        }
        for(int i= 0; i< a.length;i++)
        System.out.println(a[i]);
    }
 }

