class Solution {
    public boolean isMatch(String s, String p) {
        char[] sArray = s.toCharArray();
        char[] pArray = p.toCharArray();
        int slen = sArray.length, plen = pArray.length;
        boolean[][] dp = new boolean[slen + 1][plen + 1];

        // Initialize the last column
        dp[slen][plen] = true;
        // Initialize the last row
        for (int j = plen - 2; j >= 0; j = j - 2) {
            if (pArray[j] != '*' && pArray[j + 1] == '*') {
                dp[slen][j] = true;
            } else {
                break;
            }
        }

        for (int i = slen - 1; i >= 0; i--) {
            for (int j = plen - 1; j >= 0; j--) {
                boolean first_match = (sArray[i] == pArray[j] || pArray[j] == '.');
                if (j + 1 < plen && pArray[j + 1] == '*') {
                    dp[i][j] = dp[i][j + 2] || (first_match && dp[i + 1][j]);
                } else {
                    dp[i][j] = first_match && dp[i + 1][j + 1];
                }
            }
        }

        return dp[0][0];
    }
}