/******************************************************************************
451. Sort Characters By Frequency

Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 

Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.

*******************************************************************************/
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> counter;
        
        for(char c : s){
            counter[c]++;
        }
        
        sort(s.begin(), s.end(), 
            [&counter](const char a, const char b){
                return (counter[a] == counter[b]) ? a < b : counter[a] > counter[b];
            });
        
        return s;
    
    }
};
/*
 The code is a function that takes in two strings and returns the string sorted by frequency.
 The code iterates through each character of the first string, incrementing a counter for every character.
 It then sorts the characters of the second string based on their frequencies with an unordered_map object.
 The code attempts to sort a string by frequency of occurrence.
*/

