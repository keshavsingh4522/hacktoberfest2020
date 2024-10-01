#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
    priority_queue<long long int, vector<long long int>, greater<long long int>>q;
    q.push(1);
    long long int ans;
    for(int i=0;i<n;i++)
    {
        ans = q.top();
        q.pop();
        q.push(ans*2);
        q.push(ans*3);
        q.push(ans*5);
        while(!q.empty()&&q.top()==ans)
        q.pop();
    }
    return ans;
    }
};