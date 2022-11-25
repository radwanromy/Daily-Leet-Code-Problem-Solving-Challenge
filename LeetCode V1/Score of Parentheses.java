class Solution {
    public int scoreOfParentheses(String S) {
        Stack<Integer> stack = new Stack<>();
        // The score of the current frame
        stack.push(0);

        for (int i = 0; i < S.length(); i++) {
            if (S.charAt(i) == '(') {
                stack.push(0);
            } else {
                int x = stack.pop();
                int y = stack.pop();
                stack.push(y + Math.max(2 * x, 1));
            }
        }
        return stack.pop();
    }
}