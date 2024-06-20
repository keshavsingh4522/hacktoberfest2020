class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int> frequency(n);
        for(int i=0;i<n;i++){
            frequency[nums[i]]++;
        }
        int result=0;
        for(int i=0;i<n;i++){
            if(frequency[i]>1){
                result=i;
                break;
            }
        }
        return result;
    }
};