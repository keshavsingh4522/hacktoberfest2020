#include<iostream>
using namespace std;

int main() {

    for(int i=2;i<=100;i++) {
    bool x = true;
    
    for (int j=2;j<(i-1);j++) {

    if(i%j==0) {
        x=false;
        break;
    }

    }

    if(x==true) {
        cout<<i<<endl;
    }

    }

    return 0;
}
