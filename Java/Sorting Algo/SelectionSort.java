class SelectionSort {
    public void sort(int[] nums) {
        int n = nums.length;
        for(int i=0; i<n-1; i++){
            int min = i;
            for(int j=i+1; j<n; j++){
                if(nums[j] < nums[min])
                    min = j;
            }
            int temp = nums[i];
            nums[i] = nums[min];
            nums[min] = temp;
        }
    }
}
