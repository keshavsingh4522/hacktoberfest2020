/*
Edit Distance (Memoization and DP)
You are given two strings S and T of lengths M and N, respectively. Find the 'Edit Distance' between the strings.
Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. In order to do so, you can perform the 
following three operations:
1. Delete a character
2. Replace a character with another one
3. Insert a character

Note : Strings don't contain spaces in between.

Input format :
The first line of input contains the string S of length M.
The second line of the input contains the String T of length N.

Output format :
Print the minimum 'Edit Distance' between the strings.

Constraints :
0 <= M <= 10 ^ 3
0 <= N <= 10 ^ 3

Time Limit: 1 sec

Sample Input 1 :
abc
dc

Sample Output 1 :
2

Explanation to the Sample Input 1 :
In 2 operations we can make string T to look like string S.
First, insert character 'a' to string T, which makes it "adc".
And secondly, replace the character 'd' of string T with 'b' from the string S. This would make string T as "abc" which is also string S. 
Hence, the minimum distance.

Sample Input 2 :
whgtdwhgtdg
aswcfg

Sample Output 2 :
9
*/

#include<vector>
int editDistance(string s1, string s2) {
	//Write your code here
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int> (n + 1));
    for(int i = 0 ; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
        	 if(i == 0) {
                 dp[i][j] = j;
             } else if (j == 0) {
                 dp[i][j] = i;
             } else if(s1[i - 1] == s2[j - 1]) {
                 dp[i][j] = dp[i - 1][j - 1];
             } else {
                 dp[i][j] = 1  + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
             }
    	}
    }
    return dp[m][n];
}

// TIme Complexity : O(m*n)
// Auxillary Space : O(mn)



/*************************************************** Memoizaion ***********************************************
#include<unordered_map>

class hash_pair {
    public:
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

unordered_map<pair<int,int>, int, hash_pair> answer;

int helper(string s1, string s2, int l1, int l2) {
    if(l1 == 0 or l2 == 0) {
        return max(l1, l2);
    }
    
    pair<int,int> my_state{l1,l2};
    
    auto it = answer.find(my_state);
    
    if(it != answer.end()) {
        return it -> second;
    }
    
    if(s1[l1 - 1] == s2[l2 - 1]) {
        return answer[my_state] = helper(s1, s2, l1 - 1, l2 - 1);
    }
    
    return answer[my_state] =  1 + min(helper(s1, s2, l1 - 1, l2),
                                   min(helper(s1, s2, l1, l2 - 1),
                                  	   helper(s1, s2, l1 - 1, l2 -1)) 
                                  );
}

int editDistance(string s1, string s2) {
	//Write your code here
    return helper(s1, s2, s1.length(), s2.length());
}

// Time Complexity : O(mn) 
// Auxillary Space : O(mn);
********************************************************************************************************************/
