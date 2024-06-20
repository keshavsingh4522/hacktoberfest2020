class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<vector<int>> sub_arr;
        int n=arr.size();
        int sum=0;
        
        for (int i=0; i <n; i++){
            int mini=30000;
             for (int j=i; j<n; j++){
                 mini=min(mini,arr[j]);
                 sum=(sum+mini)%1000000007;
             }
        }
        return sum;
    }
};