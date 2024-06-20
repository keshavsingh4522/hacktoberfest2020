#include<bits/stdc++.h> 
using namespace std;
void solve()
{
    int n,start1 = 1,start2 = 2;
    bool a1 = false,a2 = false;
    cin>>n;
    vector<int> x(n),y(n);
    for(int i = 0; i < n; i ++)
    {
        x[i] = start1;
        y[i] = start2;
        start1 += 2,start2 += 2;
        if(start1 > n)
        start1 = 2;
        if(start2 > n)
        start2 = 1;
    }
    for(int i = 0 ; i< n-1; i ++)
    {
        if(abs(x[i] - x[i+1]) == 1)
            a1 = true;
        if(abs(y[i] - y[i+1]) == 1)
            a2 = true;
    }
    if(a1 && a2)
    {
        cout<<"NO SOLUTION\n";
        return ;
    }
    if(!a1)
    for(int elem: x)
    cout<<elem<<" ";
    else if(!a2)
    for(int elem : y)
    cout<<elem<<" ";

    
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}
