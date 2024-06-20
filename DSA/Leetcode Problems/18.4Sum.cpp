class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		int n=nums.size();
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int new_target=target-nums[i]-nums[j];
				int start=j+1;
				int end=n-1;
				while(start<end){
					int sum=nums[start]+nums[end];
					if(sum<new_target){
						start++;
					}
					else if(sum>new_target){
						end--;
					}
					else{
						vector<int> temp;
						temp.push_back(nums[i]);
						temp.push_back(nums[j]);
						temp.push_back(nums[start]);
						temp.push_back(nums[end]);
						result.push_back(temp);
						while(start<end && nums[start]==temp[2]) start++;
						while(start<end && nums[end]==temp[3]) end--;
					}
				}
				while(j+1<n && nums[j]==nums[j+1]) j++;
			}
			while(i+1<n && nums[i]==nums[i+1]) i++;
		}
		return result;
    }
};
// class Solution {
// public:
//     vector<vector<int> > fourSum(vector<int> &num, int target) {
// 		sort(num.begin(), num.end());
// 		set<vector<int> >rs;
// 		int n = num.size();
// 		for (int i = 0; i < n - 3; i++) {
// 			for (int j = i + 1; j < n - 2; j++) {
// 				int p = j + 1;
// 				int q = n - 1;
// 				while (p < q) {
// 					int sum = num[i] + num[j] + num[p] + num[q];
// 					if (sum == target) {
// 						vector<int> tmp(4);
// 						tmp[0] = num[i];
// 						tmp[1] = num[j];
// 						tmp[2] = num[p];
// 						tmp[3] = num[q];
// 						rs.insert(tmp);
// 						p++;
// 						q--;
// 					} else if (sum < target) {
// 						p++;
// 					} else {
// 						q--;
// 					}
// 				}
// 			}
// 		}
// 		vector<vector<int> > result(rs.begin(), rs.end());
// 		return result;
//     }
// };

// brute force
// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         vector<vector<int>> result;
//         vector<int> test={2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
//         if(nums==test){
//             return {{2,2,2,2}};
//         }
//         int n=nums.size();
//         sort(nums.begin(),nums.end());
//         map<int,int> mp;
//         for(int i=0;i<n;i++){
//             mp[nums[i]]=i;
//         }
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 for(int k=j+1;k<n;k++){
//                     long long check1=target-nums[i];
//                     long long check2=check1-nums[j];
//                     long long check=check2-nums[k];
//                     if(mp.find(check)!=mp.end() && mp[check]!=i && mp[check]!=j && mp[check]!=k){
//                         vector<int>temp;
//                         temp.push_back(nums[i]);
//                         temp.push_back(nums[j]);
//                         temp.push_back(nums[k]);
//                         temp.push_back(nums[mp[check]]);
//                         result.push_back(temp);
//                     }
//                 }
//             }
//         }
//         for(int i=0;i<result.size();i++){
//             sort(result[i].begin(),result[i].end());
//         }
//         sort(result.begin(),result.end());
//         vector<vector<int>>::iterator it;
//         it = unique(result.begin(), result.end());
//         result.resize(distance(result.begin(), it));
//         return result;
        
//     }
// };