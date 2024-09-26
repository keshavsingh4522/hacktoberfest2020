#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int maxN = 2e5+1;
const int SIZE = 4*maxN;

int N, Q, lo[SIZE], hi[SIZE], mp[maxN];
ll sum[SIZE], pre[SIZE];

void pull(int i){
    pre[i] = max(pre[2*i], sum[2*i]+pre[2*i+1]);
    sum[i] = sum[2*i] + sum[2*i+1];
}

void init(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    if(l == r){
        scanf("%lld", &sum[i]);
        pre[i] = max(0LL, sum[i]);
        mp[l] = i;
        return;
    }
    int m = (l+r)/2;
    init(2*i, l, m);
    init(2*i+1, m+1, r);
    pull(i);
}

void update(int idx, int val){
    int i = mp[idx];
    sum[i] = val;
    pre[i] = max(0LL, sum[i]);

    i >>= 1;
    while(i){
        pull(i);
        i >>= 1;
    }
}

pll query(int i, int l, int r){
    if(l > hi[i] || r < lo[i])      return {0, 0};
    if(l <= lo[i] && hi[i] <= r)    return {pre[i], sum[i]};

    pll left = query(2*i, l, r);
    pll right = query(2*i+1, l, r);
    return {max(left.first, left.second+right.first), left.second+right.second};
}

int main(){
    scanf("%d %d", &N, &Q);
    init(1, 1, N);
    for(int q = 0, t, a, b; q < Q; q++){
        scanf("%d %d %d", &t, &a, &b);
        if(t == 1)
            update(a, b);
        else if(t == 2)
            printf("%lld\n", query(1, a, b).first);
    }
}
