[Click here to see Question](https://leetcode.com/problems/number-of-good-ways-to-split-a-string/)

# 1525. Number of Good Ways to Split a String

You are given a string s, a split is called good if you can split s into 2 non-empty strings p and q where its concatenation is equal to s and the number of distinct letters in p and q are the same.

Return the number of good splits you can make in s.


**Example 1:**

Input: s = "aacaba"   <br />
Output: 2     <br />
Explanation: There are 5 ways to split "aacaba" and 2 of them are good. <br />
("a", "acaba") Left string and right string contains 1 and 3 different letters respectively.                 <br />
("aa", "caba") Left string and right string contains 1 and 3 different letters respectively.                 <br />
("aac", "aba") Left string and right string contains 2 and 2 different letters respectively (good split).    <br />
("aaca", "ba") Left string and right string contains 2 and 2 different letters respectively (good split).     <br />
("aacab", "a") Left string and right string contains 3 and 1 different letters respectively.                   <br />

**Example 2:**

Input: s = "abcd" <br />
Output: 1         <br />
Explanation: Split the string as follows ("ab", "cd"). <br />

**Example 3:**

Input: s = "aaaaa"                               <br />
Output: 4                                        <br />
Explanation: All possible splits are good.       <br />
 
**Example 4:**

Input: s = "acbadbaada"                           <br />
Output: 2                                         <br />

**Constraints:**

- s contains only lowercase English letters. 
- 1 <= s.length <= 10^5
