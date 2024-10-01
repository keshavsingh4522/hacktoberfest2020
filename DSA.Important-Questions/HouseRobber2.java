public class houserobber2 {
    class Solution {
        public int rob(int[] nums) {
                  if(nums.length==1) return nums[0];
            if(nums.length==2) return Math.max(nums[0],nums[1]);
            
            //0th index - n-2 index
            int x = helper(0,nums.length-1,nums);
            //1st index - n-1 index
            int y = helper(1,nums.length,nums);
            
            return Math.max(x,y);
        }
        
        private int helper(int start,int end,int[] nums){
            int[] dp = new int[end];
            dp[start]=nums[start];
            dp[start+1] = Math.max(nums[start],nums[start+1]);
            for(int index=start+2;index<end;index++){
                dp[index] = Math.max(dp[index-2]+nums[index],dp[index-1]);
            }
            return dp[dp.length-1];           
    
        }
    }
}
