class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum = 0;
        for(int num : nums){
            sum+=num;
        }
        
        if((sum%k)!=0) return false;
        
        int subsetSum[] = new int[k];
        return canPartitionKSubsets(nums,0,subsetSum,k,sum);
    }
    
    private boolean canPartitionKSubsets(int nums[] , int idx , int subsetSum[] , int k , int sum){
        if(idx==nums.length){
            int sumObtained = subsetSum[0];
            for(int subsetIdx = 1;subsetIdx<k;subsetIdx++){
                if(subsetSum[subsetIdx]!=sumObtained) return false;
            }
            return true;
        }
        
        for(int subsetIdx=0;subsetIdx<k;subsetIdx++){
            if(subsetSum[subsetIdx]>(sum/k)) return false;
        }
        
        for(int subsetIdx=0;subsetIdx<k;subsetIdx++){
            if(subsetSum[subsetIdx]==0){
                subsetSum[subsetIdx] = nums[idx];
                boolean canPartition = canPartitionKSubsets(nums,idx+1,subsetSum,k,sum);
                if(canPartition) return true;
                subsetSum[subsetIdx] = 0;
                break;
            }else{
                subsetSum[subsetIdx]+= nums[idx];
                boolean canPartition = canPartitionKSubsets(nums,idx+1,subsetSum,k,sum);
                if(canPartition) return true;
                subsetSum[subsetIdx]-= nums[idx];
            }
        }
        
        return false;
    }
}
