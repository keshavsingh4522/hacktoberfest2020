/* Multiples of 3 and 5 */
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=1000,required_sum=0;
    for(int i=1;i<n;i++)
    {
        if(i%3==0 || i%5==0)
        required_sum+=i;
    }
    cout<<required_sum;
    return 0;
}