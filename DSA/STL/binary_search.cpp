#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,key;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cin>>key;

    bool present=binary_search(arr,arr+n,key);
    if(present)
    cout<<"present";
    else
    cout<<"absent";
    
     auto lb=lower_bound(arr,arr+n,key);
   cout<<endl<<lb-arr;
auto ub=upper_bound(arr,arr+n,key);
   cout<<endl<<ub-arr;
   
   cout<<endl<<ub-lb;
    return 0;
}

