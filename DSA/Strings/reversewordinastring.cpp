class Solution {
public:
    string reverseWords(string s) {
        string res;
        stack<string>st;
        string str;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ' && str.size()!=0){
                st.push(str);
                str="";
            } 
          else  if(s[i]==' ' && str.size()==0){
               continue;
            } 
             else str+=s[i];
        }
    if(str.size()!=0)    st.push(str);
        while(!st.empty()){
           string ans = st.top();
            st.pop();
            res+=ans;
           if(st.size()!=0) res+=" ";
        }
        
        return res;
    }
};
