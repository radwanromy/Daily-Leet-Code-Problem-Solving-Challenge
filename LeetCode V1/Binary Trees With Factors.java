class Solution {
    private static final long MOD = 1000000007L;

    public int numFactoredBinaryTrees(int[] A) {
        if (A == null || A.length == 0) {
            return 0;
        }
        Arrays.sort(A);
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < A.length; i++) {
            map.put(A[i], i);
        }
        long[] dp = new long[A.length];
        Arrays.fill(dp, 1L);
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < i; j++) {
                if (A[i] % A[j] == 0 && map.containsKey(A[i] / A[j])) {
                    dp[i] = (dp[i] + dp[j] * dp[map.get(A[i] / A[j])]) % MOD;
                }
            }
        }

        long rst = 0L;
        for (long num : dp) {
            rst += num;
        }
        return (int) (rst % MOD);
    }
}