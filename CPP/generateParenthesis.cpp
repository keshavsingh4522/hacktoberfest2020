class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        help(n,n,0,"",ans);
        return ans;
    }
    //remaing opening brackets,remainging closing brackets,currentOpenings
    void help(int rob,int rcb,int curOs,string cur,vector<string>&ans){
        if(rob < 0 or rcb < 0 or curOs < 0)
            return;
        if(rob == 0 and rcb == 0){
            ans.push_back(cur);
            return;
        }
        
        //inserting closing bracket
        cur.push_back(')');
        help(rob,rcb-1,curOs-1,cur,ans);
        cur.pop_back();
        //insert opening bracket
        cur.push_back('(');
        help(rob-1,rcb,curOs+1,cur,ans);
        cur.pop_back();
    }
};
