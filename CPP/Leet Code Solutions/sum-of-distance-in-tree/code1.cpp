class Solution {
public:
    #define pi pair<int,int>
    #define fi first
    #define sc second
    int dfs(vector<vector<int> >&ed,vector<vector<pi>>&dp,int node,int pa,int& cnt){
        int cnt2 = 1;
        int val = 0;
        for(int i=0;i<ed[node].size();i++){
            int tempcnt = 0;
            int tempval = 0;
            if(pa!=ed[node][i])
                tempval = dfs(ed,dp,ed[node][i],node,tempcnt);
            cnt2 += tempcnt;
            val += tempval;
            dp[node].push_back({tempval,tempcnt});
        }
        cnt = cnt2;
        return cnt2+val;
    }
    
    void dfs(vector<vector<int>>&ed, vector<vector<pi>>&dp,int node,int pa,int val,vector<int>&ans,int cnt){
        int cntsum = 0;
        int valsum = 0;
        for(auto ele:dp[node]){
            cntsum += ele.sc; 
            valsum += ele.fi;
        }
        ans[node] = valsum + val;
        for(int i=0;i<ed[node].size();i++){
            if(ed[node][i]!=pa)
                dfs(ed,dp,ed[node][i],node,val+cnt+1+valsum-dp[node][i].fi+cntsum-dp[node][i].sc,ans,cnt+1+cntsum-dp[node][i].sc);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int> > ed(n);
        for(auto ele:edges){
            ed[ele[0]].push_back(ele[1]);
            ed[ele[1]].push_back(ele[0]);
        }
        vector<vector<pi> > dp(n);
        int cnt = 0;
        dfs(ed,dp,0,-1,cnt);
        // for(auto ele:dp){
        //     for(auto ele2:ele){
        //         cout<<"{"<<ele2.fi<<","<<ele2.sc<<"} ";
        //     }
        //     cout<<"\n";
        // }
        vector<int> ans(n);
        dfs(ed,dp,0,-1,0,ans,0);
        return ans;
    }
};