/* Special Pyhtagoras Triplet */
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int sum=1000,sides[3];
    bool ans;
    for(int i=1;i<=sum;i++)
    { 
        ans=false;
    for(int j=1;j<=sum;j++)
    if(sum-i+j>=0)
    {
        sides[0]=i;
        sides[1]=j;
        sides[2]=sum-(i+j);
        sort(sides,sides+3);
        if(pow(sides[0],2)+pow(sides[1],2)==pow(sides[2],2))
        {
            ans=true;
            break;
        }

    }
    if(ans)
    break;

}
cout<<sides[0]*sides[1]*sides[2];
return 0;

}
