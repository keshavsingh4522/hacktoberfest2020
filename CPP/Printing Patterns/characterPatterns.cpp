#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
char i=1;
while(i<=n){
    char j = 1;
    char chartoP = 'A';
    while(j<=n){
        // also A + j - 1 can be used to print the same thing 
        cout<<chartoP;
        chartoP+=1;
        j++;
        
    }
    cout<<endl;
    i++;
}

return 0;
}