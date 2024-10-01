/*The basic idea is, keep a hashmap which stores the characters in string as keys
and their positions as values, and keep two pointers which define the max substring. 
move the right pointer to scan through the string , and meanwhile update the hashmap. 
If the character is already in the hashmap, then move the left pointer to the right of 
the same character last found. Note that the two pointers can only move forward.*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
        int maxlen = 0;
        vector<int> lastIndex(256,-1);//stores the most recent index of character s[j]
        int i = 0;
        for(int j=0;j<n;j++)
        {
            i = max(i,lastIndex[s[j]]+1);// defines the starting index of the substring, 
// max function ensures that i does not moves backwards
           
            maxlen = max(maxlen,j-i+1);
            lastIndex[s[j]] = j;
            
           
                
        }
        
        return maxlen;
        
    }
};