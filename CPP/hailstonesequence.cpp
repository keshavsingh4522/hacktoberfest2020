#include<iostream>
using namespace std;
int count=0;
int hailstonesequence(int n){
    int x;
    if(n==1){
        count++;
        return 1;
    }
    else if(n%2==0){
        cout<<n<<" ";
        count++;
        return hailstonesequence(n/2);
        
        
    }
    else{
        cout<<n<<" ";
        count++;
        return hailstonesequence(3*n+1);
        
    }


}

int main(){
int n;
cout<<"Enter n::";
cin>>n;
    cout<<hailstonesequence(n)<<" ";
    cout<<endl<<count;

}
