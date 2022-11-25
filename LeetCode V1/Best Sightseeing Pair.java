class Solution {
    public int maxScoreSightseeingPair(int[] A) {
        int ans = 0, currBest = 0;
        for (int num : A) {
            ans = Math.max(ans, currBest + num);
            currBest = Math.max(currBest, num) - 1;
        }
        return ans;
    }
}