class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max=0;
        for(int i=0;i<accounts.size();i++){
            if(max<accumulate(accounts[i].begin(),accounts[i].end(),0)){
                max=accumulate(accounts[i].begin(),accounts[i].end(),0);
            }
        }
        return max;
    }
};