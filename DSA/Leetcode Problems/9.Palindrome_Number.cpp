#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        unsigned long long result=0;
        unsigned long long temp=x;
        while(temp/10>=0){
            unsigned long long rem=temp%10;
            result=result*10+rem;
            if(temp/10==0){
                break;
            }
            temp=temp/10;
            
        }
        if(result==x){
            return true;
        }
        else{
            return false;
        }
        
    }
};
C