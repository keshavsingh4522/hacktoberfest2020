/* Using Prefix Sum Technique
Maintain Two arrays and Using Prefix Sum

Front[] - ith index Store count of unique characters in the range [0..i]
Back[] - ith index Store count of unique characters in the range [i....n-1]

Then by comparing values of both array, we get answer in O(n) time.
*/

class Solution {
public:
    int numSplits(string s) {
        int n = s.size() ;
        int vis[26]={} , front[100005]={} , back[100005]={} ;
        int cnt=0 ;
        for(int i=0 ; i<n ; i++){
            if (!vis[s[i]-'a'])
                cnt++ , vis[s[i]-'a']++ ;
            front[i]=cnt ;
        }
        memset(vis,0,sizeof(vis)) ;
        cnt=0 ;
        for(int i=n-1 ; i>=0 ; i--){
            if (!vis[s[i]-'a'])
                cnt++ , vis[s[i]-'a']++ ;
            back[i]=cnt ;           
        }
        int ans=0 ;
        for(int i=0 ; i<n-1 ; i++){
            if (front[i]==back[i+1]) ans++ ;
        }
        return ans ;
    }
};
