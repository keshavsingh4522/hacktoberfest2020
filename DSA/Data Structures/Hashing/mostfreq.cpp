#include<bits/stdc++.h> 
using namespace std;
void solve()
{
    int n,max_freq=0,max_elem;
    cout<<"Enter number of elements in the Array: ";
    cin>>n;
    cout<<"\n Enter elements of the array: ";
    vector<int> x(n);
    for(int i = 0;i<n;i++)
    cin>>x[i];
    map<int,int> y;

    for(int elem: x)
    y[elem]++;

   for(auto it : y)
   if(it.second>max_freq)
   {
         max_freq = it.second;
         max_elem = it.first;
   }
   cout<<"\nElement with Maximum Freq is: "<<max_elem;

}
int main()
{

solve();
return 0;
}
