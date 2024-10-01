/*
problem statement:-
You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is
a concatenation of each word in words exactly once, in any order, and without any intervening characters.

You can return the answer in any order.

test case:- 
s = "barfoothefoobarman", words = ["foo","bar"]

Output [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
*/


#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
	cin>>s;
	 vector<string> words;
	 
	 for(int i=0;i<2;i++){
	 string temp;
	 cin>>temp;
	 words.push_bach(temp);
	 }
	 
	  int n=s.size();
        int len=a.size();
        int m=a[0].size();
        if(n<len*m)return {};
        map<string,int> mp;
        vector<int> ans;
        for(int i=0;i<len;i++)mp[a[i]]++;
        for(int i=0;i<=n-(len*m);i++){
            bool d=true;
            map<string,int> m2=mp;
            for(int j=0;j<len;j++){
                if(m2[s.substr(i+(j*m),m)])
                   m2[s.substr(i+(j*m),m)]--;
                else{
                    d=false;
                    break;
                }
            }
            if(d)ans.push_back(i);
           
        }
		cout<<"Index: ";
		for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
		}
    
    return 0;
}


