/******************************************************************************
1704. Determine if String Halves Are Alike

You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.

 

Example 1:

Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
Example 2:

Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.
 

Constraints:

2 <= s.length <= 1000
s.length is even.
s consists of uppercase and lowercase letters..

*******************************************************************************/
class Solution {
    public boolean halvesAreAlike(String s) {
    if (s == null || s.isEmpty()) {
        return false;
    }
    char[] chars = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    Set<Character> o = new HashSet<>();
    for (char c : chars) {
        o.add(c);
    }

    int cntPrev = 0;
    int cntLast = 0;

    for (int i = 0, j = s.toCharArray().length - 1; i < j; i++, j--) {
        if (o.contains(s.charAt(i))) {
            cntPrev++;
        }

        if (o.contains(s.charAt(j))) {
            cntLast++;
        }
    }

    return cntPrev == cntLast;
    }
}

/******************************************************************************

 The code is trying to find the number of characters in a string that are identical.
 The code starts by checking if the string is null or empty, and returns false if it is.
 If not, then it iterates through each character in the string and checks whether they are contained within an array of characters.
 For every character in the string, it will check whether they are found within an array of characters (char[]).
 It also keeps track of how many times this has happened before so that when there's a new character added to the end, it can compare with how many times this has happened before.
 The code is a Java implementation of the algorithm for determining if two strings are equal.
 The code uses an array to store characters and then iterates through the string, checking each character against the set of characters in the array.
 If a match is found, it increments the corresponding counter.

*******************************************************************************/