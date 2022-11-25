class Solution {
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> rst = new ArrayList<>();
        if (root == null)  {
            return rst;
        }
        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        while (!queue.isEmpty()) {
            int size = queue.size();
            double sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                sum += node.val;
                if (node.left != null) {
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                }
            }
            rst.add(sum / size);
        }
        
        return rst;
    }
}