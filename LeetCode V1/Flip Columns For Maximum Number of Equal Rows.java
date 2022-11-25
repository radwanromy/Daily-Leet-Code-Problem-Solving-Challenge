class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        int max = 0;
        int rows = matrix.length, cols = matrix[0].length;
        for (int i = 0; i < rows; i++) {
            int[] opposite = new int[cols];
            for (int j = 0; j < cols; j++) {
                opposite[j] = matrix[i][j] ^ 1;
            }

            int count = 0;
            for (int k = 0; k < rows; k++) {
                count += Arrays.equals(matrix[k], matrix[i]) || Arrays.equals(matrix[k], opposite) ? 1 : 0;
            }
            max = Math.max(max, count);
        }
        return max;
    }
}