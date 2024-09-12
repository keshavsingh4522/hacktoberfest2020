//https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n = nums2.size();
        int c[m+n];
        int i=0,j=0,k=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                c[k++]=nums1[i++];
            }
            else{
                c[k++]=nums2[j++];
            }
        }
        while(i<m){
            c[k++]=nums1[i++];
        }
        while(j<n){
            c[k++]=nums2[j++];
        }
        if((m+n)%2 !=0){
            return c[(m+n-1)/2];
        }
        else{
            float k =(c[(m+n)/2]+c[(m+n-2)/2])/2.0;
            return k;
        }
    }
};
