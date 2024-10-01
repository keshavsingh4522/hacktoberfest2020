#include <bits/stdc++.h>
using namespace std;

bool comp(int a,int b){
    return a<=b;
}
int main(){

    // ye to wahi denomination wali problem hai jo bhaut famous hai 
    // aur bhaut hi common hai 

    int a[]={10,50,100};int money = 25 ;
    while(money>0)
    {
    int idx=lower_bound(a,a+6,money,comp)-a-1;
    cout << a[idx]<<endl;
    money-=a[idx];}
}