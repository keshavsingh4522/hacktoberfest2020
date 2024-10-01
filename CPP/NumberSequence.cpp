
#include <iostream>
using namespace std;

int main() {
    
    int testcase=0;
    
    
    cin>>testcase;
    
    
    while(testcase-- > 0)
    {
        
    int num=0;
    cin>>num;
    
    int f=num;
    while(f>=10)
    {
        f=f/10;
    }
    int l=num%10;
    
    cout<<f+l<<"\n";    
    }    
    
    
	return 0;
}
