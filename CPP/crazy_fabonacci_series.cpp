#include <iostream>

using namespace std;

int checkPrime(int c){
    int m=0,i,flag=0;
    m=c/2;
    
    for(i=2;i<m;i++){
        if(c % i == 0)  
      {  
          flag=1;  
          break;  
      }  
    }
    
    return flag;
}

int main()
{
    int n,a=0,b=1,c=0,i,prime;
    
    cin>>n;
    
    cout<<"1 ";
    
    for(i=1;i<n;i++){
        c=a+b;
        prime=checkPrime(c);
        if(c%5 == 0)
            cout<<"0 ";
        else if(prime==0 && c!=1)
            cout<<"0 ";
        else    
        cout<<c<<" ";
        a=b;
        b=c;
    }

    return 0;
}
