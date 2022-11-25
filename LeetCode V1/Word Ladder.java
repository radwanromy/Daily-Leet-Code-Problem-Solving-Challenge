class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if (wordList == null || wordList.size() == 0) {
            return 0;
        }
        // 将 List 转换为 Set 以满足在 O(1) 的时间内查找 List 中是否包含某个单词
        // 如果使用 List 时间复杂度为 O(n),更新测试用例后会 TLE.
        Set<String> wordSet = new HashSet<>(wordList);
        if (!wordSet.contains(endWord)) {
            return 0;
        }
        
        Queue<String> queue = new LinkedList<>();
        queue.offer(beginWord);
        // 从 wordSet 中移除 beginWord,代表已经遍历过了
        wordSet.remove(beginWord);
        int level = 1;

        // BFS
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String word = queue.poll();
                if (word.equals(endWord)) {
                    return level;
                }
                for (String neigh : getNeighbors(word, wordSet)) {
                    queue.offer(neigh);
                }
            }
            level++;
        }

        return 0;
    }

    private List<String> getNeighbors(String word, Set<String> wordSet) {
        List<String> rst = new ArrayList<>();
        char[] chars = word.toCharArray();

        for (int i = 0; i < word.length(); i++) {
            char old = chars[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (ch == old) {
                    continue;
                }
                chars[i] = ch;
                String nextWord = new String(chars);
                // 看是否能够成功从 wordSet 中移除 nextWord,
                // 该操作同时包含了两个信息：nextWord在wordSet中存在；移除 nextWord,表示已经遍历过了
                if (wordSet.remove(nextWord)) {
                    rst.add(nextWord);
                }
            }
            chars[i] = old;
        }
        return rst;
    }
}
