class Solution {
    public List<Boolean> prefixesDivBy5(int[] A) {
        List<Boolean> ans = new ArrayList<>();
        int reminder = 0;
        for (int i = 0; i < A.length; i++) {
            reminder = (reminder << 1 | A[i]) % 5;
            ans.add(reminder == 0);
        }
        return ans;
    }
}