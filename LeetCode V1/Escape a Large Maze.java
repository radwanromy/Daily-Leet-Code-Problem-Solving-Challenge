class Solution {
    long MAX = 1000000;

    public boolean isEscapePossible(int[][] blocked, int[] source, int[] target) {
        if (blocked == null || blocked.length <= 0) {
            return true;
        }

        Set<Long> blockedSet = new HashSet<>();
        for (int[] block : blocked) {
            blockedSet.add(block[0] * MAX + block[1]);
        }
        return canEscape(blockedSet, source, target) && canEscape(blockedSet, target, source);
    }

    private boolean canEscape(Set<Long> blockedSet, int[] start, int[] end) {
        Set<Long> visited = new HashSet<>();
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{start[0], start[1]});
        visited.add(start[0] * MAX + start[1]);
        int area = 1;
        int[][] DIRS = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            if (curr[0] == end[0] && curr[1] == end[1]) {
                return true;
            }
            for (int[] dir : DIRS) {
                int nextR = curr[0] + dir[0], nextC = curr[1] + dir[1];
                long position = nextR * MAX + nextC;
                if (nextR < 0 || nextR >= MAX || nextC < 0 || nextC >= MAX || blockedSet.contains(position) || visited.contains(position)) {
                    continue;
                }
                queue.offer(new int[]{nextR, nextC});
                visited.add(position);
                if (++area > 19900) {
                    return true;
                }
            }
        }
        return false;
    }
}