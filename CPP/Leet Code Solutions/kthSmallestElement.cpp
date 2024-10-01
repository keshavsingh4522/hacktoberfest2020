#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k)
    {
        priority_queue<int> pq;
        for (int i = 0; i <= r; i++)
        {
            int val = arr[i];
            if (pq.size() < k)
                pq.push(val);
            else
            {
                if (pq.size() == k && val <= pq.top())
                {
                    pq.pop();
                    pq.push(val);
                }
            }
        }
        return pq.top();
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        v.push_back(input);
    }
    Solution obj;
    return 0;
}
