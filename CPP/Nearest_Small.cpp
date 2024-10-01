#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={1,2,3,4,5};
    stack<int> s;
    vector<int> v;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    {
        if(s.size()==0)
        {
            v.push_back(-1);
        }
        else if(s.size()>0 && s.top()<arr[i])
        {
            v.push_back(s.top());
        }
        else if(s.size()>0 && s.top()>=arr[i])
        {
            while(s.size()>0 && s.top()>=arr[i])
            {
                s.pop();
            }
            if(s.size()==0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top());
            }

        }
        s.push(arr[i]);

    }
    for(auto i:v)
        {
            cout<<i<<" ";
        }
}
