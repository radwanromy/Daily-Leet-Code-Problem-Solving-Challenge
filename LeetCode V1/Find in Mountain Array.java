class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {
        int peakIndex = peakIndexInMountainArray(mountainArr);

        int left = 0, right = peakIndex;
        while (left < right) {
            int mid = left + (right - left >> 1);
            if (mountainArr.get(mid) >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (mountainArr.get(left) == target) {
            return left;
        }

        left = peakIndex;
        right = mountainArr.length();
        while (left < right) {
            int mid = left + (right - left >> 1);
            if (mountainArr.get(mid) <= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left < mountainArr.length() && mountainArr.get(left) == target ? left : -1;
    }

    private int peakIndexInMountainArray(MountainArray arr) {
        int left = 0, right = arr.length() - 1;
        while (left < right) {
            int mid = left + (right - left >> 1);
            if (arr.get(mid) < arr.get(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}