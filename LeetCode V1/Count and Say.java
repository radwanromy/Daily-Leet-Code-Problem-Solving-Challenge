class Solution {
    public String countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        String ans = countAndSay(n - 1);
        return read(ans);
    }
    public String read(String ans) {
        int[] countArray = new int[100];
        countArray[ans.charAt(0)]++;

        StringBuilder sb = new StringBuilder();

        for (int i = 1; i < ans.length(); i++) {
            if (countArray[ans.charAt(i)] == 0) {
                sb.append(countArray[ans.charAt(i - 1)]);
                sb.append(ans.charAt(i - 1));
                countArray[ans.charAt(i - 1)] = 0;
            }
            countArray[ans.charAt(i)]++;
        }
        sb.append(countArray[ans.charAt(ans.length() - 1)]);
        sb.append(ans.charAt(ans.length() - 1));
        return sb.toString();
    }
}