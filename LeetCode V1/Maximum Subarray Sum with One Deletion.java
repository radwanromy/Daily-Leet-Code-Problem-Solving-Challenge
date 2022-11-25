class Solution {
    public int maximumSum(int[] arr) {
        int n = arr.length, ans = arr[0];
        int[] left = new int[n], right = new int[n];
        left[0] = arr[0];
        for (int i = 1; i < n; i++) {
            left[i] = Math.max(left[i - 1] + arr[i], arr[i]);
            ans = Math.max(ans, left[i]);
        }
        right[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = Math.max(right[i + 1] + arr[i], arr[i]);
        }
        for (int i = 1; i < n - 1; i++) {
            ans = Math.max(ans, left[i - 1] + right[i + 1]);
        }
        return ans;
    }
}