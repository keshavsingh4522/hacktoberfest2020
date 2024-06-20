class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<3) return ans;
        
    sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1,k=nums.size()-1;
            while(j<k){
                if(nums[k]+nums[j]==(-nums[i])){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    int last_left = nums[j], last_right = nums[k];
				// we have seen this number & combo before; skip
				//while (j < k && nums[j] == last_left) ++j;
				while (j < k && nums[k] == last_right) --k;
                }
                if(nums[j]+nums[k]>(-nums[i])) --k;
                if(nums[j]+nums[k]<(-nums[i])) ++j;
            }
        }
    return ans;
    
    }
};