class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(0, nums.size()-1, k, nums);
    }

    int quickSelect(int left, int right, int k, vector<int>& nums) {
        if(left == right) {
            return nums[left];
        }
        
        int pivotIdx = partition(left, right, nums);
        int tempW = pivotIdx + 1; // W smaller numbers

        if(k + tempW > nums.size() + 1) {
            return quickSelect(left, pivotIdx - 1, k, nums);
        }
        else if(k + tempW < nums.size() + 1) {
            return quickSelect(pivotIdx+1, right, k, nums);
        }
        return nums[pivotIdx];
    }


    int partition(int left, int right, vector<int>& nums) {
        /**
         * Set w smaller values in the left, larger in the right of the pivot
         * Finish in linear time.
         */

        // set pivot to end of the right
        int pivotIdx = left + (right - left)/2;
        swap(pivotIdx, right, nums);
        pivotIdx = right;
        
        // w is the numbers less equal than num[pivotIdx];
        int w = left;

        for(int i=left; i<right; i++) {
            if(nums[i] < nums[pivotIdx]) {
                swap(w, i, nums);
                w++;
            }
        }
        // swap the pivot into proper
        swap(w, pivotIdx, nums);
        return w;
    }

    void swap(int aIdx, int bIdx, vector<int>& nums) {
        int temp = nums[aIdx];
        nums[aIdx] = nums[bIdx];
        nums[bIdx] = temp;
    }
};