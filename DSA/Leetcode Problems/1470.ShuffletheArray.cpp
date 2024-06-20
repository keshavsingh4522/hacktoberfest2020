class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result;
        int i=0,j=n;
        int flag=0;
        while(i<n && j<2*n){
            if(flag==0){
                result.push_back(nums[i]);
                flag=1;
                i++;
            }
            else if(flag==1){
                result.push_back(nums[j]);
                flag=0;
                j++;
            }
        }
        result.push_back(nums[j]);
        return result;
    }
};