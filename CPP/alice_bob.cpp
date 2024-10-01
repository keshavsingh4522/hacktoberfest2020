#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std ;

int main(){
    int i , a[3] , b[3];
    int score_alice =0 ;
    int score_bob=0;
    for(i=0;i<3;i++){
        cin>>a[i];
    }
    for(i=0;i<3;i++){
        cin>>b[i];
    }
    
    if (a[i]>b[i]){
        score_alice ++;
    }
    else if (a[i]<b[i]){
        score_bob ++ ;
    }
    else
    {
        return 0 ;
    }

    cout<<score_alice<<score_bob <<endl;
    

}
