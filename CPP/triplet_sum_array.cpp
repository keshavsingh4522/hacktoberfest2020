#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
   
        long long int n,sum;
        cin>>n>>sum;

        long long int a[n],i;

        for(i=0;i<n;++i)
          cin>>a[i];

        sort(a,a+n);

        long long int j,k,f=0;
        
        for(i=0;i<n;++i)
        {
            j=i+1;
            k=n-1;
        

        while(j<k)
        {
            if(a[i]+a[j]+a[k]==sum)
            {
                f=1;
                break;
            }
            else if(a[i]+a[j]+a[k]<sum)
                j++;
            else
                k--;
        }
        
        if(f)
           break;
        }
    if(f)
      cout<<1<<endl;
    else
      cout<<0<<endl;

return 0;
}