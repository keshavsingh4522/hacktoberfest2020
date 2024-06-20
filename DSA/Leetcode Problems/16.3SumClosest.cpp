#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i, j, k;
        int n = nums.size();
        int close=10000;
        int result=0;
        for (i = 0; i < n - 2; i++) {
            j = i+1;
            k = n-1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(target-sum)<close){
                    close=abs(target-sum);
                    result=sum;
                }
                if (sum == target) {
                    return sum;
                    j++;
                    k--;
                } else if (sum > target) {
                    k--;
                } else if (sum < target) {
                    j++;
                }
            }
        }
        return result;
    }
};
int main(){
    Solution obj;
    vector<int> hello={-1,2,1,-4};
    int target=1;
    cout<<obj.threeSumClosest(hello,target);
}
// class Solution {
// public:
//     int threeSumClosest(vector<int>& nums, int target) {
//         sort(nums.begin(),nums.end());
//         vector<int> result;
//         int i, j, k;
//         int n = nums.size();
//         for (i = 0; i < n - 2; i++) {
//             j = i+1;
//             k = n-1;
//             while (j < k) {
//                 int sum = nums[i] + nums[j] + nums[k];
//                 result.push_back(sum);
//                 if (sum == target) {
//                     j++;
//                     k--;
//                 } else if (sum > target) {
//                     k--;
//                 } else if (sum < target) {
//                     j++;
//                 }

//             }
//         }
//         auto it1=upper_bound(result.begin(),result.begin()+result.size(),target);
//         auto it2=lower_bound(result.begin(),result.begin()+result.size(),target);
//         if(*it1-target>*it2-target){
//             return *it2;
//         }
//         else{
//             return *it1;
//         }
        
//     }
// };

/*
#include <bits/stdc++.h> 
using namespace std; 
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        vector<int> closest;
        vector<int> sums;
        vector<int> close;
        int i;
        int sum2=0;
        sort(nums.begin(),nums.end());
        int max=*max_element(nums.begin(),nums.end());
        int min=*min_element(nums.begin(),nums.end());
        if(target>max){
            return(nums[n-1]+nums[n-2]+nums[n-3]);
        }
        else if(target<min){
            return(nums[0]+nums[1]+nums[2]);
        }
        else{
            // for (int i=0; i<n-2; i++)
            // {
            //     for (int j=i+1; j<n-1; j++)
            //     {
            //         for (int k=j+1; k<n; k++)
            //         {
            //             int sum=nums[i]+nums[j]+nums[k];
            //             sums.push_back(sum);
            //             int diff=sum-target;
            //             closest.push_back(diff);
            //         }
            //     }
            // }
            if(target >0){
                for( i=0;i<nums.size()-2;i++){
                    int sum=nums[i]+nums[i+1]+nums[i+2];
                    close.push_back(target-sum);
                }
                int min=*min_element(close.begin(),close.end());
                for(i=0;i<nums.size()-2;i++){
                sum2=nums[i]+nums[i+1]+nums[i+2];
                    if(target-sum2==min){
                        break;
                    }
                }
            }
            else{
                for( i=0;i<nums.size()-2;i++){
                    int sum=nums[i]+nums[i+1]+nums[i+2];
                    close.push_back(sum+target);
                }
                int min=*min_element(close.begin(),close.end());
                for( i=0;i<nums.size()-2;i++){
                sum2=nums[i]+nums[i+1]+nums[i+2];
                    if(target+sum2==min){
                        break;
                    }
                }
            }
        }
        return sum2;
        // int j;
        // int mini=*min_element(closest.begin(),closest.end());
        // for(j=0;j<closest.size();j++){
        //     if(closest[j]==mini){
        //         break;
        //     }
        // }

    }
};
int main(){
    Solution obj;
    vector<int> hello={-1,2,1,-4};
    int target=1;
    cout<<obj.threeSumClosest(hello,target);
}
/*
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        vector<int> close;
        sort(nums.begin(),nums.end());
        int i;
        int sum2=0;
        if(target >0){
            for( i=0;i<nums.size()-2;i++){
                int sum=nums[i]+nums[i+1]+nums[i+2];
                close.push_back(target-sum);
            }
            int min=*min_element(close.begin(),close.end());
            for( i=0;i<nums.size()-2;i++){
               sum2=nums[i]+nums[i+1]+nums[i+2];
                if(target-sum2==min){
                    break;
                }
            }
        }
        else{
            for( i=0;i<nums.size()-2;i++){
                int sum=nums[i]+nums[i+1]+nums[i+2];
                close.push_back(sum+target);
            }
            int min=*min_element(close.begin(),close.end());
            for( i=0;i<nums.size()-2;i++){
               sum2=nums[i]+nums[i+1]+nums[i+2];
                if(target+sum2==min){
                    break;
                }
            }
        }
        return sum2;
    }
};*/