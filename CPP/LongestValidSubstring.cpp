#include <bits/stdc++.h>
#include<stack>
#include<vector>
using namespace std;

 class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        stack<int>st;
        st.push(-1);
       int max_length =0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    int len = i-st.top();
                    max_length = max(max_length, len);
                }
            }
        }
        return max_length;
    }
 };

int main()
 {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.findMaxLen(s)<<endl;

    }
	return 0;
}