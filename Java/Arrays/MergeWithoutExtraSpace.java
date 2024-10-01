package Arrays;                                              /*  Name - Tanisha Bhadani  */
import java.util.*;
class GFG {
    // Driver code
    public static void main(String[] args) throws Exception {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            String inputLine[] = br.readLine().trim().split(" ");
            int n = Integer.parseInt(inputLine[0]);
            int m = Integer.parseInt(inputLine[1]);
            int arr1[] = new int[n];
            int arr2[] = new int[m];
            inputLine = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                arr1[i] = Integer.parseInt(inputLine[i]);
            }
            inputLine = br.readLine().trim().split(" ");
            for (int i = 0; i < m; i++) {
                arr2[i] = Integer.parseInt(inputLine[i]);
            }

            new Solution().merge(arr1, arr2, n, m);

            StringBuffer str = new StringBuffer();
            for (int i = 0; i < n; i++) {
                str.append(arr1[i] + " ");
            }
            for (int i = 0; i < m; i++) {
                str.append(arr2[i] + " ");
            }
            System.out.println(str);
        }
    }
}// } Driver Code Ends


class Solution {

    public void merge(int arr1[], int arr2[], int n, int m) {
       
       int p1=0;
       int p2=0;
       int p3=n-1;
       
     
           while(p1<=p3 && p2<m)
           {
                   if(arr1[p1]<arr2[p2])
                        p1++;
                    else
                    {
                        int temp=arr1[p3];
                        arr1[p3]=arr2[p2];
                        arr2[p2]=temp;
                        
                        p2++;
                        p3--;
                    }
                    
           }
           
           Arrays.sort(arr1);
           Arrays.sort(arr2);
           
            
       
    }
}