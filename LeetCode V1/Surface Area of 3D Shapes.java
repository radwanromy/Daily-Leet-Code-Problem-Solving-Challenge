class Solution {
    public int surfaceArea(int[][] grid) {
        if (grid == null || grid.length == 0) {
            return 0;
        }

        int result = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                // 如果该位置存在 tower
                if (grid[i][j] > 0) {
                    result += 2 + 4 * grid[i][j];
                }
                // 减去重合部分的面积
                if (i > 0) {
                    result -= Math.min(grid[i][j], grid[i - 1][j]) * 2;
                }
                if (j > 0) {
                    result -= Math.min(grid[i][j], grid[i][j - 1]) * 2;
                }
            }
        }
        return result;
    }
}