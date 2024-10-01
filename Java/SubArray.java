public class Program
{
    public static void main(String[] args) {
        
        
        
        int arr[]={1,2,0,7,2};
        
    
        for(int i=0;i<arr.length;i++)
        {
           int sum=0;
            for(int j=i;j<arr.length;j++)
            {
                
                sum=sum+arr[j];
              // System.out.println(arr[j]+" ");
              System.out.print(sum+" ");
               
            }
            
        
            
        }
    }
}
