class Solution {
    public int[] twoSum(int[] nums, int target) {
     
       /* for(int i=0; i<nums.length; i++){
            for(int j=i; j<nums.length; j++){
                if(nums[i]+nums[j] == target && i!=j){
                     return new int[]{i,j};
                }
            }
    }
    return new int[]{};  */
        
      int len = nums.length;
        Map<Integer,Integer> list=new HashMap<>();
        
        for(int i=0; i<len; i++){
            list.put(nums[i],i);
        }
        
        for(int i = 0 ; i < len; i++){
            int temp=target-nums[i];
            Integer val=list.get(temp);  //yha map se value direct get kr re h ,wrapper class use krenge
            if(val!=null && i!=val){  //yha pr empty k lie null use krenge 
                //abhi ek aur condition aegi ,soch ,bilul shi.yeahhhh
                return new int[]{i,val};
            }
        }
        
        return new int[]{};
    }
}

