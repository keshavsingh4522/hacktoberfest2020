class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int> >  edges(n);
        //vector<int> vis(n);
        vector<int> indeg(n);
        vector<int> ans;
        for(auto ele:pre){
            edges[ele[1]].push_back(ele[0]);
            indeg[ele[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            //vis[node] = 1;
            ans.push_back(node);
            for(auto ele:edges[node]){
                indeg[ele]--;
                if(indeg[ele]==0)
                    q.push(ele);
            }
        }
        //bool ok = true;
        for(auto ele:indeg)
            if(ele){
                return vector<int>();
            }
        return ans;
    }
};