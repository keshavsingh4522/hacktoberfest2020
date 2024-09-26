// LEETCODE QUESTION LINK : https://leetcode.com/problems/minimum-score-triangulation-of-polygon/

//code : 
class Solution {
public:
    int minScoreTriangulation(vector<int> &arr, int si, int ei, vector<vector<int>> &dp){
        if(ei - si == 1){ 
            // 2 points cannot form triangle, thats why return 0;
            return dp[si][ei] = 0;
        }
        
        if(ei - si == 2){
            // when we have 3 points, that means, we can form a triangle
            return dp[si][ei] = arr[si]* arr[si+1]* arr[ei];
        }
        
        if(dp[si][ei] != -1){
            return dp[si][ei];
        }
        
        int minRes = (int)1e8;
        for(int cut = si + 1; cut < ei; cut++){ //fixing starting point and ending point. points between (si < cut < ei) will be treated as a possible option to form a triangle.
            int lres = minScoreTriangulation(arr, si, cut, dp);
            int rres = minScoreTriangulation(arr, cut, ei, dp);
            
            minRes = min(minRes, lres + rres + arr[si]*arr[cut]*arr[ei]);
        }
        
        return dp[si][ei] = minRes;
    }
    
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return minScoreTriangulation(values, 0, n-1, dp);
    }
};
