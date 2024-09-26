#include <iostream>
using namespace std;

void weird(int n){
    if(n>1){
        if(n%2!=0){
            cout << n*3+1<<" ";
            return weird(n*3+1);
        }
        else{
            cout<< n/2<<" ";
            return weird(n/2);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<n<<" ";
    weird(n);

    return 0;
}