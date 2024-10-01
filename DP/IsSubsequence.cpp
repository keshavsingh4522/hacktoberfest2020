class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() <= 0) return true;
        
        int ps=0, pt=0;
        while (pt < t.size()) {
            if (s[ps] == t[pt]) {
                ps++; pt++;
                if (ps >= s.size()) return true;
            }else {
                pt++;
            }
        }
        
        return false;
    }
};
