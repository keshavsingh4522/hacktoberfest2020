class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0){
            return 0;
        }
        
        if (divisor == 1){
            return dividend;
        }
        
        if (divisor == -1){
            if (dividend == INT_MIN){
                return INT_MAX;
            }else{
                return -dividend;
            }
        }
        
        int sign = 1;
        if (dividend > 0){
            sign = -sign;
            dividend = -dividend;
        } 
        if (divisor > 0){
            sign = -sign;
            divisor = -divisor;
        }
        
        int res = divideCore(dividend, divisor).first;
        if (sign < 0){
            res = -res;
        }
        
        return res;
        
    }
    
    pair<int, int> divideCore(int dividend, int divisor){
        pair<int, int> res;
        res.first = 0;
        if (divisor >= -1073741824){
            int divisor2 = divisor + divisor;
            if (dividend <= divisor2){
                pair<int, int> r = divideCore(dividend, divisor2);
                res.first = 2 * r.first;
                dividend = r.second;
            }
        }
        if (dividend <= divisor){
            res.first ++;
            dividend -= divisor;
        }
        res.second = dividend;
        
        return res;
    }
};
