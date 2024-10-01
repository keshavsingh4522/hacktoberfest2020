/*
Problem Statement
Given a text and a wildcard pattern of size N and M respectively, implement a wildcard pattern matching algorithm that finds if the wildcard pattern is matched with the text. The matching should cover the entire text not partial text.
The wildcard pattern can include the characters ‘?’ and ‘*’
 ‘?’ – matches any single character 
 ‘*’ – Matches any sequence of characters(sequence can be of length 0 or more)

 'TEXT' and 'PATTERN' contain only lowercase letters and patterns may contain special characters ‘*’ and ‘?’
 */
#include<iostream>
using namespace std;
bool wildcardMatching(string pattern, string text)
{
    int n = pattern.length();
    int m = text.length();

    //base case
    if(m==0 and n==0){             //if both the strings are empty - they'll match
        return true;
    }
    else if(n==0){                 //if pattern is empty - there are no characters left in pattern to match with text
        return false;
    }
    else if(m==0){                 //if text is empty then it can match with pattern only when pattern contains only "*"(1 or more than 1)
    	bool found = false;
    	for(int i=0;i<n;i++){
    		if(pattern[i]!='*'){
    			found = true;
    			break;
    		}
    	}
    	return (!found);
    }
    
    if(pattern[0]=='*'){
        bool ans1 = wildcardMatching(pattern.substr(1),text);
        bool ans2 = wildcardMatching(pattern,text.substr(1));
        return ans1 or ans2;
    }
    else if(pattern[0]=='?' or pattern[0]==text[0]){
        return wildcardMatching(pattern.substr(1),text.substr(1));
    }
    return false;
}

int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		string p,t;
		cin>>p;
		cin>>t;
		bool ans = wildcardMatching(p,t);
		(ans) ? cout<<"True" : cout<<"False";
		cout<<endl;
	}
	return 0;
}