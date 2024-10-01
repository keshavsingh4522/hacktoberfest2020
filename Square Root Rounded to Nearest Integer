class Solution {
   public int mySqrt(int x) {
     if (x<2) return x;
     long ans = 0, l=1, r=x;
     while(1<=r) {
       long mid = (1+r)/2;
       if ((mid*mid)<=x) {
         ans=Math.max(ans,mid);
         l=mid+1;
       } else r = mid-1;
     }
     return (int)ans;
   }
}
