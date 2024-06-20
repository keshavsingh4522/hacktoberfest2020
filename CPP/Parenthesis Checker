class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack <char> st;
        char temp;
        map<char,char> mp;
        mp['}']='{';
        mp[')']='(';
        mp[']']='[';
        map<char,char>::iterator itr;
        for(int i=0;i<x.size();i++){
            if(x[i]=='{' || x[i]=='(' || x[i]=='['){
                st.push(x[i]);
            }
            if(x[i]=='}' || x[i]==')' || x[i]==']'){
                if(st.empty()){
                    return false;
                }
                else{
                    temp=st.top();
                    itr=mp.find(x[i]);
                    if(temp==itr->second){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return st.empty()?true:false;
    }

};
