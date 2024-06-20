/* Smallest Multiple */
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int required_no=1,upto_divided=20;
    bool possible;
    while(1)
    {   possible=true;
        for(int i=1;i<=upto_divided;i++)
        if(required_no%i)
        {
            possible=false;
            break;
        }
        if(possible)
        break;
        required_no++;
    }
    cout<<required_no;
    return 0;
}