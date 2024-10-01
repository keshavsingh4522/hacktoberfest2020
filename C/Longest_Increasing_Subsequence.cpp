// this is the code to print length of LIS
// time complexity is O(nlogn)
// it is just to print length, sequence can't be printed from it

#include<bits/stdc++.h>
using namepsace std;

int LIS(int arr[],int n){
    vector<int> v;
    v.push_back(arr[0]);
    for(int i=1;i<n;i++){
        auto itr=lower_bound(v.begin(),v.end(),arr[i]);
        if(itr==v.end())    v.push_back(arr[i]);
        else    *itr=arr[i];
    }
    return v.size();
}
