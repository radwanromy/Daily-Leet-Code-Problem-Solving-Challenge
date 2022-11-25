class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> stack = new Stack<>();
        for (int asteroid : asteroids) {
           
            while (!stack.isEmpty() && stack.peek() > 0 && stack.peek() < -asteroid) {
                stack.pop();
            }
           
            if (stack.isEmpty() || asteroid > 0 || stack.peek() < 0) {
                stack.push(asteroid);
            } else if (asteroid < 0 && stack.peek() == -asteroid) {
               
                stack.pop();
            }
        }

        int[] rst = new int[stack.size()];
        for (int i = rst.length - 1; i >= 0; i--) {
            rst[i] = stack.pop();
        }
        return rst;
    }
}