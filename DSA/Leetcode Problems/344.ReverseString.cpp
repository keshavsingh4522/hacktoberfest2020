class Solution {
public:
    void reverseString(vector<char>& s) {
        int l=0;
        int r=s.size()-1;
        while(l<=r){
            swap(s[l],s[r]);
            l++;
            r--;
        }
    }
};//using recursion
class Solution {
public:
    void reverseString(vector<char>& s) {
        _reverseString(s,0,s.size()-1);
    }
    void _reverseString(vector<char>& s,int start,int end){
        if(start>end) return;
        swap(s[start++],s[end--]);
        _reverseString(s,start,end);
    }
};