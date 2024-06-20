
#include <stdio.h>

int main()
{
    long int val,cvl;
    
    int siz=0;
    scanf("%ld",&val);
    
    cvl=val;
    
    while(val>0){
        siz++;
        val/=10;
    }
    
    if(siz==2){
        printf("0.%ld",cvl);
    }

   else if(siz==1){
        printf("0.0%ld",cvl);
    }

    else{
    
    int arr[siz];
    
    for(int i=siz-1;i>=0;i--){
        arr[i]=cvl%10;
        cvl=cvl/10;
    }
    
    
    
    int noofextra=(siz-2);
    
    if(noofextra%3==0){
        noofextra=(noofextra/3)-1;
    }
    else{
         noofextra=(noofextra/3);
    }
    
    noofextra+=1;
    
    char carr[siz+noofextra];
    int posi=(siz+noofextra)-3;
    posi=posi-3;
    
    int i=(siz+noofextra)-1;
    int pos=(siz+noofextra)-1;
    
    
    
    while(i>=0 && pos>=0){
        
        if(i==((siz+noofextra)-3)){
            carr[pos]='.';
            carr[pos-1]=arr[i-noofextra]+'0';
            pos-=2;
            
            
            
        }
        else if(i==posi){
            carr[pos]=',';
            posi=posi-3;
           
            carr[pos-1]=arr[i-noofextra]+'0';
            pos-=2;
            
            
            
            
        }
        else{
            
            carr[pos]=arr[i-noofextra]+'0';
            
         pos--;
         
            
        }
        
        
         i--;
        
    }
    
    for(int i=0;i<siz+noofextra;i++){
        printf("%c",carr[i]);
    }
    
    }
    
   
    return 0;
}
