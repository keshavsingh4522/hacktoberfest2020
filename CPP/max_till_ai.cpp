#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int a[6], i, mx=-1;
    for(i=0;i<6;i++){
        cin>>a[i];
        mx = max(mx, a[i]);
        cout<<mx<<" ";
    }
}
