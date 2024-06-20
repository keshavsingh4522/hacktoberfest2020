class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> s;
        for(auto i:tokens){
            if(i=="+" || i=="-" || i=="*" || i=="/"){
                int sn=s.back(); s.pop_back();
                int fn=s.back(); s.pop_back();
                
                if(i=="+")
                    s.push_back(fn+sn);
                else if(i=="-")
                    s.push_back(fn-sn);
                else if(i=="*")
                    s.push_back(fn*sn);
                else 
                    s.push_back(fn/sn);
            }
            else 
                s.push_back(stol(i,NULL,10));
        }

        return s.back();
    }
};
