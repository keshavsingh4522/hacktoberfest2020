#include <iostream>
#include <vector>
using namespace std; 
template<typename T>
void pop_front(vector<T> &v)
{
    if (v.size() > 0) {
        v.erase(v.begin());
    }
}
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[0]==val){
                pop_front(nums);
            }
            else{
                int a=nums[0];
                pop_front(nums);
                nums.push_back(a);
            }
        }
        return nums.size();
    }
};
int main(){
    Solution obj;
    vector<int> nums={0,1,2,2,3,0,4,2};
    int val=2;
    cout<<obj.removeElement(nums,val);
}