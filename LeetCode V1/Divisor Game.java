class Solution {
    public boolean divisorGame(int N) {
        int[] mem = new int[N + 1];
        return canWin(mem, N);
    }

    private boolean canWin(int[] mem, int n) {
        if (n == 1) {
            return false;
        }
        if (mem[n] != 0) {
            return mem[n] == 1;
        }

        boolean win = false;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                win |= !canWin(mem, n - i);
            }
        }
        mem[n] = win ? 1 : 2;

        return win;
    }
}