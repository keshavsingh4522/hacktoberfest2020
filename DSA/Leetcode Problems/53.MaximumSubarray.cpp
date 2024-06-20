//order of n^3
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> result;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1){
                int sum=0;
                for(int k=i;k<=j;k++){
                    sum=sum+nums[k];
                }
                result.push_back(sum);
            }
        }
        return *max_element(result.begin(),result.end());    
    }
};
//order of n^2
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> result;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<=n-1;j++){
                sum=sum+nums[j];
                result.push_back(sum);
            }
            
        }
        return *max_element(result.begin(),result.end());    
    }
};
//order of n kadane's algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=INT_MIN;
        for(auto it:nums){
            sum+=it;
            maxi=max(sum,maxi);
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
};
