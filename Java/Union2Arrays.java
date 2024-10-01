package geeksforgeeks;
import java.util.*;

public class Union2Arrays {

	public static void main(String[] args) {
	
		Scanner sc=new Scanner(System.in);
		int cas=sc.nextInt(); 
		
		while(cas-->0){
		    int k=0;
		    HashMap<Integer,Integer> hm=new HashMap<>();
		    int i=0,j=0;
		    int m=sc.nextInt();
		    int n=sc.nextInt();
		    int A[]=new int[m];
		    int B[]=new int[n];
		    
		    for( i=0;i<m;i++){
		       A[i]=sc.nextInt();
		       hm.put(A[i],i);
		       
		    }
		    
		     for( j=0;j<n;j++){
		       B[j]=sc.nextInt();
		       if(!hm.containsKey(B[j])){
		           hm.put(B[j],i+j);
		           
		           
		       }
		    }
		    
		    System.out.println(hm.size());
		   
		   
		    
		    
		    
		    
		}
	}

		
		
	}
	


