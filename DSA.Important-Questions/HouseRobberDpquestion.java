// This is famous quetions of Dynamic Programming  all approaches discuss here

public class houserobberleetcode {
   
    //     public int rob(int[] nums) {
    //         return robFrom(nums,0);
    //     }
    //         private int robFrom(int[] wealth, int currIndex){
    //             if(currIndex>=wealth.length) // Base case
    //                 return 0;
                
    //             int stealCurr = wealth[currIndex] + robFrom(wealth, currIndex+2);
    //             int skipCurr = robFrom(wealth, currIndex+1);
            
                
    private int currrob;

            //             return Math.max(stealCurr, skipCurr);  
               public int rob(int[] num) {
        // int rob = 0; //max monney can get if rob current house
        // int notrob = 0; //max money can get if not rob current house
        // for(int i=0; i<num.length; i++) {
        //     int currob = notrob + num[i]; //if rob current value, previous house must not be robbed
        //     notrob = Math.max(notrob, rob); //if not rob ith house, take the max value of robbed (i-1)th house and not rob (i-1)th house
        //     rob = currob;
        // }
        // return Math.max(rob, notrob);
                   int rob = 0;
                   int notrob = 0;
                   Object nums;
                for(int i =0; i<nums.length; i++){
                       int currob = notrob + nums[i];
                       notrob = Math.max(notrob, rob);
                       rob = currrob;
                   }    
                   return Math.max(rob,notrob);
        }
    }
    