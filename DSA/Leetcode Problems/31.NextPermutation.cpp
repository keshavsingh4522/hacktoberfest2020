#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool val=next_permutation(nums.begin(),nums.end());
        if(val==false){
            sort(nums.begin(),nums.end());
        }
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
    }
};
int main(){
    Solution obj;
    vector<int> nums={1,2,3};
    obj.nextPermutation(nums);
}