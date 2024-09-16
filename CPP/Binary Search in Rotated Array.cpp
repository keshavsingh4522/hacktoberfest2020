int reverse_binary(vector<int>&nums,int target,int l,int r){
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return -1;
    }
    int binarysearch(vector<int>&nums,int target,int l,int r){
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==1){
            if(nums[0]==target){
                return 0;
            }
            else{
                return -1;
            }
        }
    
        int t=0;
        for(int i=0;i<n-1;i++){
            if((nums[0]<=nums[i]) &&(nums[i+1]<=nums[n-1]) ){
                t=i;
                int t1=binarysearch(nums,target,0,t);
                int l1=binarysearch(nums,target,t+1,n-1);
                if(t1==-1 && l1==-1)return -1;
                if(t1!=-1)return t1;
                return l1;
            }
            else if(nums[0]<nums[n-1]){
                return binarysearch(nums,target,0,n-1);
            }
        }
        return reverse_binary(nums,target,0,n-1);
        
    }
