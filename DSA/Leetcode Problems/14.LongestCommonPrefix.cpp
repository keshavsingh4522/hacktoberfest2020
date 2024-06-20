#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int minSizeIndex=0;
        int minSize=strs[0].size();
        for(int i=1;i<strs.size();i++){
            if(minSize>strs[i].size()){
                minSize=strs[i].size();
                minSizeIndex=i;
            }
        }
        int flag=true;
        for(int j=0;j<strs[minSizeIndex].size() && flag==true;j++){
            int count=0;
            for(int k=0;k<strs.size();k++){
                if(strs[k][j]==strs[minSizeIndex][j]){
                    count++;
                }
            }
            //cout<<count;
            if(count==strs.size()){
                //cout<<strs[minSizeIndex][j]<<" ";
                ans+=strs[minSizeIndex][j];
                flag=true;
            }
            else{
                flag=false;
            }
        }
        return ans;
    }
};
int main(){
    vector<string>strs={"flower","flow","flight"};
    Solution obj;
    cout<<obj.longestCommonPrefix(strs);
}