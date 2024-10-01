#include<bits/stdc++.h>
#include<numeric>
#include<math.h>
using namespace std;
const int INF = 1e9;
const int N = 1e7+3;
int main()
{
    int n; cin>>n;
    vector<int> a(n);

    for(int i=0; i<n; i++)
        cin>>a[i];

    int curr = 0, maximum = 0;

    for(int i=0; i<n; i++){
        int curr += a[i];

        maximum = max(maximum, curr);
        if(curr < 0){
            curr = 0;
        }
    }

    cout<<maximum<<endl;
    return 0;
}