class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> num3;
        nums1.insert( nums1.end(), nums2.begin(), nums2.end() );
        sort(nums1.begin(),nums1.end());
        int size=nums1.size();
        if(size%2==0){
            return (float)(nums1[ceil(size/2)-1]+nums1[ceil(size/2+1)-1])/2;
        }
        else{
            return (float)nums1[ceil(size/2)];
        }
    }
};