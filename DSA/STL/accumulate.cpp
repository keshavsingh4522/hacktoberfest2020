// Simple C++ code to understand the accumulate function in CPP
// This inbuild function is used to add the the element in the range [start,end)
#include<bits/stdc++.h>
using namespace std;
int main()
{
  
vector<int>v={23,4,56,23,67,76,1};
 
  int sum=0;  
  sum= accumulate(v.begin(),v.end(),0);   //all the value in vector is added to 0// assign to sum;
  cout<<sum<<endl;
  return 0;
}
