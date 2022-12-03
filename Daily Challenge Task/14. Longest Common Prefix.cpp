/******************************************************************************
14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.

*******************************************************************************/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       if(strs.size() == 0) return "";
        int res = INT_MAX;
        for(int i = 0; i < strs.size()-1; i++){
            res = min(res, (int)min(strs[i].size(), strs[i+1].size()));
            while(strs[i].substr(0, res) != strs[i+1].substr(0, res)){
                res--;
            }
            if(res == 0)return "";
        }
        return strs[0].substr(0, res);  
    }
};
/*
  The code is a function that returns the longest common prefix of two strings.
 The code starts by checking if there are no strings passed in, and if so it will return "".
 If there are strings passed in, then the code will iterate through them to find their longest common prefix.
 It does this by finding the minimum length between each string's size and comparing it with the next string's size until they reach 0.
 Once they reach 0, they stop looking for longer common prefixes and return "".
 The code returns the longest common prefix of two strings.
*/

