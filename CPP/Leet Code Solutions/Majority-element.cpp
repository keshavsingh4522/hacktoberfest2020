//question link
//https://leetcode.com/problems/majority-element/ 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        vector<int> count;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]]>nums.size()/2) return nums[i];
        }
        return -1;
    }
};