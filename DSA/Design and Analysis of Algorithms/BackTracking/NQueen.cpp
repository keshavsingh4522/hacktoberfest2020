#include<bits/stdc++.h> 
using namespace std;
bool isValid(vector<int> &x)
{
    int n = x.size();

    for(int i = 0 ; i < n ; i ++ )
    for(int j = 0 ; j < n ; j ++ )
    if( (j != i) and (x[i]!= -1 and x[j]!= -1) and (abs(i-j) == abs(x[i]-x[j]) or x[i]==x[j]))
    return false;

    return true; 
}
void NQueen(vector<int> x,int n,int index = 0)
{
    if(!isValid(x))
    return;

    if(index == n)
    {
        for(int elem : x)
        cout<<elem+1<<" ";
        cout<<"\n";   
        return ;
    }
    for(int i = 0 ; i < n ; i ++)
    {
        x[index] = i;
        NQueen(x,n,index +1);
    }


}
void solve()
{

    int n ;
    cin>>n;
    vector<int> x(n,-1);
    NQueen(x,n);

}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}
