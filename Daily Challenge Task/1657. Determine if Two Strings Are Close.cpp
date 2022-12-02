
/******************************************************************************
1657. Determine if Two Strings Are Close

Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

 

Example 1:

Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"
Example 2:

Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.
Example 3:

Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"
 

Constraints:

1 <= word1.length, word2.length <= 105
word1 and word2 contain only lowercase English letters.

*******************************************************************************/
class Solution {
public:
    bool closeStrings(string word1, string word2) {
    if (word1.length() != word2.length())
      return false;
    unordered_map<char, int> count1;
    unordered_map<char, int> count2;
    string s1;           
    string s2;         
    vector<int> freqs1;  
    vector<int> freqs2;  
    for (const char c : word1)
      ++count1[c];
    for (const char c : word2)
      ++count2[c];
    for (const auto& [c, freq] : count1) {
      s1 += c;
      freqs1.push_back(freq);
    }
    for (const auto& [c, freq] : count2) {
      s2 += c;
      freqs2.push_back(freq);
    }
    sort(begin(s1), end(s1));
    sort(begin(s2), end(s2));
    if (s1 != s2)
      return false;
    sort(begin(freqs1), end(freqs1));
    sort(begin(freqs2), end(freqs2));
    return freqs1 == freqs2;
  
    }
};

/*
 The code is trying to compare the two strings, word1 and word2.
 The code starts by creating a map of characters that will be used in counting how many times they appear in each string.
 Then it creates two vectors, one for each string, with the frequencies of all the characters from both strings.
 Next it sorts them so that they are in order from least frequent character to most frequent character.
 Finally it compares their sorted order and returns true if they match up or false otherwise.
 The code is a solution to the problem of finding if two strings are equal.
 The function takes two string arguments and compares them by comparing their lengths, then it creates an unordered_map for each word with a char key and an int value which will be used as the frequency of that character in the word.
 The code then iterates through each character in both words and stores its frequency in both maps.
 Next, it sorts both lists using begin() and end().
 Finally, it compares the sorted lists using sort() to determine if they are equal or not.
*/