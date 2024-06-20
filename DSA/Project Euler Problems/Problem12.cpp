#include<bits/stdc++.h>
using namespace std;
int no_of_divisors(long long int  n)
{
    int divisors = 1,count =1;
    while(n%2==0)
    {
        n/=2;
        count++;
    }
    //cout<<count;
    divisors*=count;
    for(int i=3;i<=sqrt(n);i++)
    {   count =1;
        while(n%i==0)
        {
            n/=i;
            count++;
        }
        divisors*=count;
    }
    if(n>2)
    divisors*=2;
     return divisors;
}
int main()
{
    const int divisors_check =500;
    long long int sum = 0,i=1;
    do{   
        sum+=i,i++;
        
    }while(no_of_divisors(sum)<divisors_check);
    cout<<sum;

    return 0;
}