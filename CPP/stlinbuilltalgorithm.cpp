#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> n;
    }
    int min=*min_element(v.begin(),v.end());
    cout<<min<<endl;
    int max=*max_element(v.begin(),v.end());
    cout<<max<<endl;
    int sum =accumulate(v.begin(),v.end(),0);//vector sum upto range and initial value
    int ct=count(v.begin(),v.end(),v[2]);//return 2
    cout<<sum<<endl<<ct<<endl;
    int element=*find(v.begin(),v.end(),2);
    auto it=v.begin();
    if( it !=v.end()){
              cout<<*it<<endl;
    }
    else
    cout<<"not found"<<endl;
    return 0;
}