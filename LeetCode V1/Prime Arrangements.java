class Solution {
    private static final int MOD = 1000000007;
    
    public int numPrimeArrangements(int n) {
        boolean[] isPrime = new boolean[n + 1];
        Arrays.fill(isPrime, 2, n + 1, true);
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        int primeCount = 0;
        for (int i = 0; i < isPrime.length; i++) {
            primeCount += isPrime[i] ? 1 : 0;
        }
        return (int)(permutation(primeCount) * permutation(n - primeCount) % MOD);
    }
    
    private long permutation(int n) {
        long count = 1L;
        while (n > 0) {
            count = count * n-- % MOD;
        }
        return count;
    }
}