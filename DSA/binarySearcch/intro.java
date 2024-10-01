package Algo.binarySearcch;

public class intro {

	public static void main(String[] args) {
		int[] a = {10,20,30,40,50,60,70,80,90,100};
      int data = 70;
      
      int l=0;
      int h=a.length-1;
      while( l<= h ) {
    	  int m = (l+h)/2; 
    	  if(data> a[m]) {
        	  l = m+1;
          }else if(data< a[m]) {
        	  h=m-1;
          }else {
        	  System.out.println(m);
        	  return;
          }
      }
      System.out.println(-1);
	}

}
