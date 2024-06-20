#include<bits/stdc++.h> 
using namespace std;
void solve()
{
    int n,m;
    cout<<"Enter number of elements in the first array: ";
    cin>>n;
    vector<int> x(n);

    cout<<"\nEnter elements in the first array: ";

    for(int i = 0;i<n;i++)
    cin>>x[i];

    cout<<"\nEnter number of elements in the second array: ";
    cin>>m;

    vector<int> y(m);

    cout<<"\nEnter elements in the second array: ";
    for(int i =0;i<m;i++)
    cin>>y[i];

    map<int,int> alpha;

    for(int elem:y)
    { 
       alpha[elem]++;
    }

    cout<<"\nElements present in first array only are: ";

    for(int i = 0 ;i<n;i++)
    if(alpha.find(x[i])==alpha.end())
    cout<<x[i]<<" ";
    
    
   
   
    
}
int main()
{

solve();
return 0;
}
