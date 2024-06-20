class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> arr(2);
        map<int,int> mapping;
        for(int i=0;i<nums.size();i++)
            mapping[nums[i]]=i;
        for(int i=0;i<nums.size();i++){
            int compare=target-nums[i];
            if(mapping[compare] && mapping[compare]!=i){
                arr[0]=i;
                arr[1]=mapping[compare];
            }
        }
        return arr;
    }
};