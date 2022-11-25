class Solution {
    public int missingNumber(int[] nums) {
        Set<Integer> numSet = new HashSet<Integer>();
        // store the elements in nums
        for (int num : nums) {
            numSet.add(num);
        }

        int expectedNumCount = nums.length + 1;
        // iterator the set to find the missing number
        for (int number = 0; number < expectedNumCount; number++) {
            if (!numSet.contains(number)) {
                return number;
            }
        }
        return -1;
    }
}