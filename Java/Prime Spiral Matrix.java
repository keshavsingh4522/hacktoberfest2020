import java.util.*;
class prime_spiral_matrix
{
    void main()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of the matrix:-");
        int m=sc.nextInt();
        int a1[][]=new int[m][m]; 
        System.out.println("Spiral Form:-");
        int x=0,y=m-1;
        int c=2,c1=1; 
        int p=0;
        while(c1<=(m*m))
        {
          
            for(int t=x;t<=y;)
            {

                p=prime(c);
                if(p==1)
                {
                    a1[x][t]=c;
                    c++;
                    c1++;
                    t++;
                }
                else
                c++;
            }
         
            for(int t=x+1;t<=y;)
            {
                
                p=prime(c);
                if(p==1)
                {
                    a1[t][y]=c;
                    c++;
                    c1++;
                    t++;
                }
                else
                c++;
            }
         
            for(int t=y-1;t>=x+1;)
            {
               
                p=prime(c);
                if(p==1)
                {
                    a1[y][t]=c;
                    c++;
                    c1++;
                    t--;
                }
                else
                c++;
            }
        
            for(int t=y;t>=x+1;)
            {
              
                p=prime(c);
                if(p==1)
                {
                    a1[t][x]=c;
                    c++;
                    c1++;
                    t--;
                    
                }
                else
                c++;
            }
            x++;
            y--;
          
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {

                System.out.print(a1[i][j]+"\t");
            }
            System.out.println();                
        }
    }
    int prime(int x)
    {
        int c=0;
        for(int i=1;i<=x;i++)
        {
            if(x%i==0)
            c++;
        }
        if(c==2)
        return 1;
        else
        return 0;
        
    }
}
