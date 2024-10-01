
 
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
 
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
using namespace std;
int main(){
 
cout<<"Enter the time"<<endl;
int h,m,s;
cin>>h>>m>>s;
while(1){
    s++;
if(s>59){
    s=0;
    m++;
}
if(m>59){
    m=0;
    h++;
}
if(h>12){
    h=1;
}
cout<<h<< " "<<m<<" "<<s<<endl;
cout.flush();
sleep(1);

system("clear"); 
}

}
