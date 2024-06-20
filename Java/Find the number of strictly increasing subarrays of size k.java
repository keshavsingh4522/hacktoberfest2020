import java.io.*;
import java .util.*;

class Main{
  public static int sub(int A[],int n,int k){
    int ans=0,curr=1;
    for(int i=1;i<n;i++){
     if(A[i-1]<A[i]){
       curr++;
     }
     else {
       if(curr>=k){
       ans+=curr-k+1;
       }  
       curr=1;
     }
    }
    if(curr>=k)
      ans+=curr-k+1;
    return ans;
  }
public static void main(String args[]){
  Scanner sc=new Scanner(System.in);
  int n,k;
  System.out.println("Enter the number of elements in array"); 
  n=sc.nextInt();
  int A[]=new int[n];
  for(int i=0;i<n;i++){
      System.out.println("Enter element "+(i+1)); 
    A[i]=sc.nextInt();
  }
  System.out.println("Enter value of k");
  k=sc.nextInt();
  int ans=sub(A,n,k);
  System.out.println("Number of strictly increasing subarrays of size k is "+ans);
 }
} 
