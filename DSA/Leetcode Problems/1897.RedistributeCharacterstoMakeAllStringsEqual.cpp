class Solution {
public:
    bool makeEqual(vector<string>& words) {
        map<char,int>mp;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                mp[words[i][j]]++;
            }
        }
        int n=words.size();
        int flag=0;
        for(auto i:mp){
            if(i.second%n!=0){
                flag=1;
                break;
            }
        }
        if(flag==0){
            return true;
        }
        else{
            return false;
        }
    }
};