#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            ans.push(nums[i]);
        }
        int result;
        while(k--)
        {
        result=ans.top();
            ans.pop();
        }
        return result;
    }
};