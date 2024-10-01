//Given a non-negative integer x, compute and return the square root of x.

class Solution {
public:
    int mySqrt(int x) {
        long long int low = 0, high = (long long int)(x);
        long long int mid;
        if(x <= 1)return x;
        while((high - low) > 1){
            mid = low + (high - low) / 2;
            long long int sqr = (mid * mid);
            if(sqr > x){
                high = mid;
            }else{
                low = mid;
            }
        }
        return (int)low;
    }
};
