#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll arr[n];
        for(ll i=0;i<n;i++)  cin >> arr[i];
        ll temp = 0;
        if(n<=1)  cout << "0" << endl;
        else if(arr[0] == 0) cout << "-1" << endl;
        else
        {
            // cout << "Hello " <<endl;
            ll maxReach = arr[0],step = arr[0],jump =1,i=1;   
            for (i = 1; i < n; i++) 
            { 
                if (i == n-1) 
                {
                    temp = 1;
                    cout << jump << endl;
                    break; 
                }
                maxReach = max(maxReach, i+arr[i]);  
                step--;
                if (step == 0) 
                { 
                    jump++; 
                    if(i >= maxReach)
                    { 
                        temp = 1;
                        cout << "-1" << endl;
                        break; 
                    }
                    step = maxReach - i; 
                } 
            }
            // cout << temp << endl;
            if(temp == 0)
                cout << "-1" << endl;
        }
    }
}
}