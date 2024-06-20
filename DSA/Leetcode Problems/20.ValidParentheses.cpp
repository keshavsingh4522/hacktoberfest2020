#include<iostream>
#include<vector>
#include<stack>
#include<map>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char,char> mp={
            {'(',')'},
            {'[',']'},
            {'{','}'},
        };
        for(char c:s){
            if(c=='(' || c=='[' || c=='{'){
                st.push(c);
            }
            else if(!st.empty() && c!='(' && c!='[' && c!='{' ){
                if(mp[st.top()]==c){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                st.push(c);
            }
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    string strs="{{[()[]{}]}}";
    Solution obj;
    bool ans=obj.isValid(strs);
    cout<<ans;
}