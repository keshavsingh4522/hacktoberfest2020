class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     int s=nums.size();
     if(s==0)
         return 0;
     int f=nums[0];
        int i;
        int j=1;
        for(i=1;i<s;i++)
        {
            if(nums[i]!=f)
            {
                f=nums[i];
                nums[j]=f;
                j++;
            }
        }
        return j;
    }
};
