#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
char i=1;
while(i<=n){
    char j = 1;
    char chartoP = 'A'+i-1;
    while(j<=i){
        cout<<chartoP;
        chartoP+=1; 
        j++;
        }
    cout<<endl;
    i++;
}
return 0;
}