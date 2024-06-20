//Sort an array of 0’s 1’s 2’s without using extra space or sorting algo 
// 1st method O(N·log(N)
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//     }
// };
//2nd method:counting sort O(N) in 3 iteration
//3rd method:3 pointer method O(N) one iteration
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>::iterator it1;
        vector<int>::iterator it2;
        vector<int>::iterator it3;
        it1=nums.begin();
        it2=nums.begin();
        it3=nums.end()-1;
        while(it2<=it3){
            if(*it2==0){
                int temp=*it1;
                *it1=*it2;
                *it2=temp;
                it1++;
                it2++;
            }
            else if(*it2==1){
                it2++;
            }
            else{
                int temp=*it3;
                *it3=*it2;
                *it2=temp;
                it3--;
            }
        } 
    }
};

