bool should_i_swap(int a,int b){
  if(a>b){
    return true;
  }
  else{
    return false;
  }
}//it is comprator function chnage condition in function and sorting method is changed
///////////////////////////////////////////////////////
// inbuilt sort function
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++ )
  {
    cin>>a[i];
  }
  sort(a,a+n);
  for(int i=0;i<n;i++)
  {
    cout<<a[i]<<" ";
  }
vector<int> x;
for (int  i = 0; i < n; i++)
{
    int x;
    cin>>x;
}


for (int i = 0; i <n ; i++)
{
    for(int j=i+1;j<n;j++){
        if(should_i_swap(a[i],a[j])){
            swap(a[i],a[j]);
        }
    }
}

  
}
// it work on introsort it is a mix of qqick sort,heap sort,insertion sort
/////////////////////////////////////
// comprator function help us to define custom sorting behaviour