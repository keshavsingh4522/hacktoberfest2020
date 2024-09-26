
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return 0;
        if(x == 0) return 1;
        long long st = x, en = 0;
        while(x > 0){
            en = en*10 + x%10;
            x/=10;
        }
        if(en == st) return 1;
        else return 0;
    }
};
