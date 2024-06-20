#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int k = 0;
        int n = nums.size();
        for(int b = n / 2; b >= 1; b /= 2)
        {
            while(k+b < n && nums[k+b] <= target)
                k += b;
        }
        
        if (nums[k] == target) 
        {
            return k;
        }
        
        return -1;
    }
};

int main()
{
    Solution s1;
    int t;
    vector<int> vec = {-1,0,3,5,9,12};
    cout<< "enter the target";
    cin>>t; // code to read custom target
    cout << s1.search(vec, t); 
    
    return 0;
}
