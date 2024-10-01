class Solution {
    public int maxSubArray(int[] nums) {

	// variable decleration and given
        int l=nums.length;
        int i=0,s=0,max=nums[0];
        int[] b = new int[l];

        // for all negative elements
        while(i!=l)
        {
            b[i]=nums[i];
            i++;
        }
        // if(l==1)
        //     return nums[0];
        Arrays.sort(b);
        if(b[l-1]<=0)
            return b[l-1];
	/* If last element after sorting is less than 0 every element is negative*/

	// for atleast one non-negative element 
        i=0;
	// finding the sum
        while(i!=l)
        {
            s+=nums[i];
	// if sum is less than 0 initialize sum to 0
            if(s<0)
            {
                s=0;
            }
	// returning the max sum
            else if(s>max)
                max=s;
            System.out.println(max);
            i++;
        }
        System.out.println(max);
        return max;
    }
}
