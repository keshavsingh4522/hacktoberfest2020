import java.io.*;

public class ARRAYlar
{
	public static void main (String []arg) throws IOException
	{
		int n,i,large;
		int []a = new int[100];
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		System.out.println("How Many Elements You Wants?");
		n=Integer.parseInt(br.readLine());
		
		System.out.print("Enter Array Elements : ");
		for(i=0; i<n; i++)
       {
           a[i]=Integer.parseInt(br.readLine());
       }  
       large = a[0];
      
       for(i=0; i<n; i++)
       {
           if(large < a[i])
           {
               large = a[i];
           }
           
       }
             System.out.print("Largest Number = " +large); 
    } 
	
}
