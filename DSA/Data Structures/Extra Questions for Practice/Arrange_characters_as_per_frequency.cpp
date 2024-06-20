#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main()
{
    string letters, l;
    int i=0;
    cin>>letters;
    
    int  flag = 1, count = 1 ,  j , k , x=0, lenx=0;
    char temp[26];
    int c[26];
    int len = letters.length();
 
  for( i=0 ; i<len-1 ; i++)
  {
      for(k=0 ; k<len ; k++)
      {
          if(letters[i] == temp[k])
            {flag = 0;}
      }
       
      if(flag != 0)
      {
          for(j=i+1 ; j<len ; j++)
          {
              if(letters[i] == letters[j])
              {
                  count++;
              }
          }
            cout<<letters[i]<<" "<<count<<" ";
            //l[x]=letters[i];
            l[x]=letters[i];
            c[x]=count;
            x++;
            lenx=x;
        }
        flag = 1;
      count = 1;
      temp[i] = letters[i];
   }
   cout<<endl;        // upto frequency calculation
 

  int loop;
  cin>>loop;

  while(loop--)
    {
          
  string templ="";
  int tempc[lenx]={0};
  int w=0;
  for(i=0 ; i<lenx ;i++)
  {
      templ[i]=l[i];
      tempc[i]=c[i];
  }
  

  
      int N , y =0 , z =0 , i1=0 , i2=0 , lenB = 0 ,lenE =0 , lenM=0, zz=0;
      int arBc[lenx]={0}, arEc[lenx]={0} , arMc[lenx]={0};
      char arBl[lenx]={0} , arEl[lenx]={0}, arMl[lenx]={0};
      j=0;
      cin>>N;
      for( i=0 ; i<lenx ; i++)
      {
          if(tempc[i]==N)
          {
              i1=i;
              break;
          }
      }
      for( i=lenx-1 ; i>=0 ; i--)
      {
          if(tempc[i]==N)
          {
              i2=i;
              break;
          }
      }
      
      for(j=i1 ; j<=i2 ; j++)
      {
          if(tempc[j] < N)
          {
              arBc[y] = tempc[j];
              arBl[y] = templ[j];
              lenB = y;
              y++;
          }
          if(tempc[j] > N)
          {
              arEc[z] = tempc[j];
              arEl[z] = templ[j];
              lenE = z;
              z++;
          }
      }
      
      for(j=i1+1 ; j<i2 ; j++)
      {
          if(tempc[j] == N)
          {
              arMc[zz] = tempc[j];
              arMl[zz] = tempc[j];
              zz++;
              lenM = zz;
          }
      }
      

      
      
      int v=0;
      if(lenB != 0)
      for( v =lenB ; v>=0 ; v--)        ///1
      {  
        cout<<arBl[v]<<" "<<arBc[v]<<" ";
      } 
        
    //cout<<"$$";
      for( i = 0; i<=i1 ; i++ )      //2
      {
      cout<<templ[i]<<" "<<tempc[i]<<" ";
      }

     
  //  cout<<"$$";
        for(k =i1 ; k<lenM ;k++)    ///3
        {
               cout<<arMl[k]<<" "<<arMc[k]<<" ";
        }
//    cout<<"$$";    
      for( j = i2; j<lenx ; j++ )     //4
      {
        cout<<templ[j]<<" "<<tempc[j]<<" ";
      }
      
          //cout<<"$$";
          if(lenE != 0)
      for( v =0 ; v<=lenE ; v++)    //5
      {
        cout<<arEl[v]<<" "<<arEc[v]<<" ";
        
      }
      
      
        if(lenB!=0)
         for( v =lenB ; v>=0 ; v--)
      {
           c[w]=arBc[v];
          l[w]=arBl[v];
          w++;
      }
      for( i = 0; i<=i1 ; i++ )
      {
          c[w]=tempc[i];
           l[w]=templ[i];
           w++;
      }
       for(k =i1; k<lenM ;k++)    ///3
        {
               c[w]=arMc[k];
               l[w]=arMl[k];
                w++;
            
        }
      
       for( j = i2; j<lenx ; j++ )
       {
           c[w]=tempc[j];
          l[w]=templ[j];
          w++;
       }
      
      if(lenE != 0)
       for( v =0 ; v<=lenE ; v++)
      {c[w]=arEc[v];
          l[w]=arEl[v];
          w++;}
    
            cout<<endl;
           
    }

 
 return 0;
 
}