#include<iostream>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='I'){
                if(s[i+1]=='V'){
                    ans+=4;
                    i=i+1;
                }
                else if(s[i+1]=='X'){
                    ans=ans+9;
                    i=i+1;
                }
                else{
                    ans=ans+1;
                }
            }
            else if(s[i]=='V'){
                ans=ans+5;
            }
            else if(s[i]=='X'){
                if(s[i+1]=='L'){
                    ans+=40;
                    i=i+1;
                }
                else if(s[i+1]=='C'){
                    ans=ans+90;
                    i=i+1;
                }
                else{
                    ans=ans+10;
                }
            }
            else if(s[i]=='L'){
                ans=ans+50;
            }
            else if(s[i]=='C'){
                if(s[i+1]=='D'){
                    ans+=400;
                    i=i+1;
                }
                else if(s[i+1]=='M'){
                    ans=ans+900;
                    i=i+1;
                }
                else{
                    ans=ans+100;
                }
            }
            else if(s[i]=='D'){
                ans=ans+500;
            }
            else if(s[i]=='M'){
                ans=ans+1000;
            }
        }
        return ans;
        
    }
};