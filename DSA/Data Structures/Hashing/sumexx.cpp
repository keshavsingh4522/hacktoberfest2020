#include<bits/stdc++.h> 
using namespace std;
void solve()
{
    int n,sum,a,b;
    bool exists = false;
    cout<<"Enter the Number of elements in array: ";
    cin>>n;
    cout<<"\nEnter the elements of array: ";
    vector<int> x(n);
    map<int,int> y;

    for(int i = 0;i<n;i++)
    cin>>x[i];
    
    cout<<"\nEnter sum to be checked for: ";
    cin>>sum;

   for(int i = 0;i<x.size();i++)
   {
          y[x[i]] = i;
   }

    for(int i = 0;i<x.size();i++)
    {
        if(y.find(sum-x[i])!=y.end() && y[sum-x[i]]!=i)
        {
            a = x[i];
            b = sum - x[i];
            exists = true;
            break;
        }
    }
 
  if(exists)
  cout<<"\n Yes, the numbers are "<<a<<" and  " <<b;
  else
  cout<<"\n No, such numbers don't exist";




}
int main()
{

solve();
return 0;
}
