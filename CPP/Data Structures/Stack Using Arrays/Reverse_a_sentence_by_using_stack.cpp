#include<bits/stdc++.h>
#include<stack>
using namespace std;
int main()
{
    string s="";
    cout<<"Enter a string :";
    cin>>s;
    stack<string> st;
    string word="";
    for(int i=0;i<s.length();i++)
    {

        if(s[i]!=' ')
        {
            word+=s[i];   
        }
        else
        {
            // cout<<st.top()<<endl;
            st.push(word);
            word="";
        }
        
        // cout<<st.top()<<endl;
    }

    while(!st.empty())
    {
       cout<<st.top()<<" ";
       st.pop();
    }
    return 0;
    

}