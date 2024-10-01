#include <bits/stdc++.h>
using namespace std;
const int N = 1e7;
vector<int> segTree(N, 0);

int makeTree(int ct, vector<int> &a, int l, int r)
{
    if (l == r)
    {
        segTree[ct] = a[l];
        return segTree[ct];
    }
    int mid = (l + r) / 2;
    segTree[ct] = makeTree(ct * 2 + 1, a, l, mid) + makeTree(ct * 2 + 2, a, mid + 1, r);
    return segTree[ct];
}

int findSum(int ct, int sr, int ed, int l, int r)
{
    if (sr >= l && ed <= r)
    {
        return segTree[ct];
    }
    if (sr > r || ed < l)
    {
        return 0;
    }
    int mid = (sr + ed) / 2;
    return findSum(ct * 2 + 1, sr, mid, l, r) + findSum(ct * 2 + 2, mid + 1, ed, l, r);
}

int main()
{
    vector<int> v = {2, 4, 1, 3, 9, 6, 7, 8, 5, 7};
    makeTree(0, v, 0, v.size() - 1);
    int l, r;
    cin >> l >> r;
    std::cout << findSum(0, 0, v.size() - 1, l, r) << std::endl;
    return 0;
}