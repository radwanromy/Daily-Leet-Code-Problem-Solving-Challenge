class Solution {
    public int findMinStep(String board, String hand) {
        if (board == null || board.length() == 0) {
            return 0;
        }
        Map<Character, Integer> balls = new HashMap<>();
        for (char c : hand.toCharArray()) {
            balls.put(c, balls.getOrDefault(c, 0) + 1);
        }
        return dfs(board, balls);
    }

    private int dfs(String board, Map<Character, Integer> balls) {
        if (board == null || board.length() == 0) {
            return 0;
        }

        int rst = Integer.MAX_VALUE;
        int i = 0, j;
        while (i < board.length()) {
            j = i + 1;
            Character color = board.charAt(i);
            while (j < board.length() && color == board.charAt(j)) {
                j++;
            }
            int costBalls = 3 - (j - i);
            if (balls.containsKey(color) && balls.get(color) >= costBalls) {
                String newBoard = shrink(board.substring(0, i) + board.substring(j));
                balls.put(color, balls.get(color) - costBalls);
                int subRst = dfs(newBoard, balls);
                if (subRst >= 0) {
                    rst = Math.min(rst, costBalls + subRst);
                }
                balls.put(color, balls.get(color) + costBalls);
            }
            i = j;
        }

        return rst == Integer.MAX_VALUE ? -1 : rst;
    }

    private String shrink(String board) {
        int i = 0, j;
        while (i < board.length()) {
            j = i + 1;
            Character color = board.charAt(i);
            while (j < board.length() && color == board.charAt(j)) {
                j++;
            }
            if (j - i >= 3) {
                board = board.substring(0, i) + board.substring(j);
                i = 0;
            } else {
                i++;
            }
        }
        return board;
    }
}