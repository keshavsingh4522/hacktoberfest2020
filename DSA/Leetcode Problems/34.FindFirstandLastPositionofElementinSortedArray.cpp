#include <iostream>
#include <algorithm>
#include <vector>
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        if(binary_search(nums.begin(),nums.begin()+nums.size(),target)){
            auto it1=lower_bound(nums.begin(),nums.begin()+nums.size(),target);
            auto it2=upper_bound(nums.begin(),nums.begin()+nums.size(),target);
            result.push_back(it1-nums.begin());
            result.push_back(it2-nums.begin()-1);
            return result;
        }
        else{
            // result.push_back(-1);
            // result.push_back(-1);
            return {-1,-1};
        }
    }
};
int main(){
    Solution s;
    vector<int> nums={5,7,7,8,8,10};
    int target=8;
    vector<int> result=s.searchRange(nums,target);
}