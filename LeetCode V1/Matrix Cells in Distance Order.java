class Solution {
    public int[][] allCellsDistOrder(int R, int C, int r0, int c0) {
        int[][] ans = new int[R * C][2];
        int index = 0;

        Queue<int[]> queue = new LinkedList<>();
        boolean[][] visited = new boolean[R][C];
        queue.offer(new int[]{r0, c0});
        visited[r0][c0] = true;

        int[][] DIRS = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            ans[index][0] = curr[0];
            ans[index++][1] = curr[1];

            for (int[] dir : DIRS) {
                int nextX = curr[0] + dir[0], nextY = curr[1] + dir[1];
                if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C || visited[nextX][nextY]) {
                    continue;
                }
                queue.offer(new int[]{nextX, nextY});
                visited[nextX][nextY] = true;
            }
        }

        return ans;
    }
}