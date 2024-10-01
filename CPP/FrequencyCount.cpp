#include<bits/stdc++.h>
#include<unordered_map>


using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    unordered_map<int,int> mp;
    for(int i = 0; i<n; i++)
    {
        mp[arr[i]]++;
    }

    for(auto i: mp)
    {
        cout << "Frequency of " << i.first << " : " << i.second << endl;
    }

}