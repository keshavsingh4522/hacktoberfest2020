/* Sum Square Difference */
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int no_of_terms=100,sum_of_square=0,square_of_sum=0;
    for(int i=1;i<=no_of_terms;i++)
    {
        sum_of_square+=pow(i,2);
        square_of_sum+=i;
    }
    square_of_sum=pow(square_of_sum,2);
    cout<<square_of_sum-sum_of_square;
    return 0;


}