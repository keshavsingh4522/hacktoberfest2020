#include <iostream>
#include<cstring>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(i%2)
           cout<<"I hate ";
        else
            cout<<"I love ";
        if(i==n)
            cout<<"it";
        else
            cout<<"that ";
    }
    cout<<"\n";
    return 0;
}
