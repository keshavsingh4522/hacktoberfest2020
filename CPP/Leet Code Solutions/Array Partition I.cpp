class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());  // sorting the array in O(n logn) time
		int result = 0;
		for(int itr = 0; itr < nums.size(); itr += 2){  //increment iterator each time by 2, further explanation is down below
			result += nums[itr]; // store the sum 
		}
		return result;
    }
};
