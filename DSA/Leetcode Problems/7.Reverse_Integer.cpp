#include <bits/stdc++.h> 
using namespace std; 
class Solution {
public:
    int reverse(int x) {
        long int rev=0;
        while(x!=0){
           int pop= x%10;
            x=x/10;
            rev = rev*10 +pop;  
        }
        if(rev<INT_MIN|| rev>INT_MAX)
            return 0;
        
        return rev;
    }
};
int main(){
    Solution obj;
    int t=obj.reverse(-123);
    cout<<t;
}
/*
int reverse(long x) {
        stringstream ss;
        string s;
        ss<<x;
        ss>>s;
        int n = s.length(); 
        for (int i = 0; i < n / 2; i++) 
            swap(s[i], s[n - i - 1]);
        stringstream geek(s);
        int k=0;
        geek>>k;
        return k;
    }
*/ 