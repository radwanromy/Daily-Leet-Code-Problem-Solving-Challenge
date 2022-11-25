class Solution {
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        TreeMap<Integer, TreeMap<Integer, TreeSet<Integer>>> tree = new TreeMap<>();
        dfs(root, 0, 0, tree);

        List<List<Integer>> ans = new ArrayList<>();
        for (TreeMap<Integer, TreeSet<Integer>> map : tree.values()) {
            ans.add(new ArrayList<>());
            for (TreeSet<Integer> set : map.values()) {
                for (Integer value : set) {
                    ans.get(ans.size() - 1).add(value);
                }
            }
        }

        return ans;
    }


    private void dfs(TreeNode root, int x, int y, TreeMap<Integer, TreeMap<Integer, TreeSet<Integer>>> tree) {
        if (root == null) {
            return;
        }

        tree.computeIfAbsent(x, key -> new TreeMap<Integer, TreeSet<Integer>>());
        tree.get(x).computeIfAbsent(y, key -> new TreeSet<Integer>());
        tree.get(x).get(y).add(root.val);
        dfs(root.left, x - 1, y + 1, tree);
        dfs(root.right, x + 1, y + 1, tree);
    }
}