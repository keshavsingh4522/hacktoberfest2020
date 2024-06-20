class Solution {
public:
    int check(string haystack, string needle,int index){
        bool flag=true;
        if(index+needle.size()>haystack.size()){
            return false;
        }
        for(int i=0;i<needle.size();i++){
            if(needle[i]==haystack[i+index]){
                flag=true;
            }
            else{
                flag=false;
                break;
            }
        }
        return flag;
    }
    int strStr(string haystack, string needle) {
        if(needle.empty()){
            return 0;
        }
        if(haystack.empty()){
            return -1;
        }
        int ans=-1;
        for(int i=0;i<haystack.size();i++){
            if(haystack[i]==needle[0]){
                int a;
                a=check(haystack,needle,i);
                if(a==1){
                    ans=i;
                    break;
                }
                else{
                    continue;
                }
            }
            else{
                continue;
            }
        }
        return ans;
    }
};