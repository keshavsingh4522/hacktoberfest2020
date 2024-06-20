#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int can_be_eaten=candyType.size()/2;
        vector<int> v=candyType;
        vector<int> ::iterator ip;
        sort( v.begin(), v.end() );
        v.erase( unique( v.begin(), v.end() ), v.end() );
        return v.size();
        if(v.size()>can_be_eaten){
            return can_be_eaten;
        }
        else{
            return v.size();
        }
    }
};
int main(){
    Solution s;
    vector<int> temp={100000,0,100000,0,100000,0,100000,0,100000,0,100000,0};
    int result=s.distributeCandies(temp);
    cout<<result;
}