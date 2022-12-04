/******************************************************************************

2256. Minimum Average Difference
Medium

You are given a 0-indexed integer array nums of length n.

The average difference of the index i is the absolute difference between the average of the first i + 1 elements of nums and the average of the last n - i - 1 elements. Both averages should be rounded down to the nearest integer.

Return the index with the minimum average difference. If there are multiple such indices, return the smallest one.

Note:

The absolute difference of two numbers is the absolute value of their difference.
The average of n elements is the sum of the n elements divided (integer division) by n.
The average of 0 elements is considered to be 0.
 

Example 1:

Input: nums = [2,5,3,9,5,3]
Output: 3
Explanation:
- The average difference of index 0 is: |2 / 1 - (5 + 3 + 9 + 5 + 3) / 5| = |2 / 1 - 25 / 5| = |2 - 5| = 3.
- The average difference of index 1 is: |(2 + 5) / 2 - (3 + 9 + 5 + 3) / 4| = |7 / 2 - 20 / 4| = |3 - 5| = 2.
- The average difference of index 2 is: |(2 + 5 + 3) / 3 - (9 + 5 + 3) / 3| = |10 / 3 - 17 / 3| = |3 - 5| = 2.
- The average difference of index 3 is: |(2 + 5 + 3 + 9) / 4 - (5 + 3) / 2| = |19 / 4 - 8 / 2| = |4 - 4| = 0.
- The average difference of index 4 is: |(2 + 5 + 3 + 9 + 5) / 5 - 3 / 1| = |24 / 5 - 3 / 1| = |4 - 3| = 1.
- The average difference of index 5 is: |(2 + 5 + 3 + 9 + 5 + 3) / 6 - 0| = |27 / 6 - 0| = |4 - 0| = 4.
The average difference of index 3 is the minimum average difference so return 3.
Example 2:

Input: nums = [0]
Output: 0
Explanation:
The only index is 0 so return 0.
The average difference of index 0 is: |0 / 1 - 0| = |0 - 0| = 0.
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105

*******************************************************************************/
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
    const int n = nums.size();
    long long suffix = accumulate(begin(nums), end(nums), 0LL);
    long long prefix = 0;
    int best = INT_MAX;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      prefix += nums[i];
      suffix -= nums[i];
      int cur = abs(prefix / (i + 1) - (i == n - 1 ? 0 : suffix / (n - i - 1)));
      if (cur < best) {
        best = cur;
        ans = i;
      }
    }
    return ans;
    }
};

/*
 The code calculates the average difference of each index.
 The first element is 1, so the average difference for that index is 0.
 The second element is 2, so the average difference for that index is 1.
 The third element is 3, so the average difference for that index would be 2.
 The code computes the average difference of the index i.
 The purpose is that when i = 0, it will return 1 and when i = n - 1, it will return 0.
 The code is calculating the average of a list.
 The first line is creating an empty list, and then adding two numbers to it.
 The second line is returning the sum of those two numbers divided by 2.
 The third line is returning the average of that number divided by 2.
 The fourth line returns the index with the minimum difference between its value and 0 (the average).
 The code will return the index with the minimum average difference.
 If there are multiple such indices, it will return the smallest one.
 The code is calculating the average difference of index 0, 1, and 2.
 The code starts by declaring a variable called nums to be an array with 5 elements.
 It then sets the value of nums to [2,5,3,9,5,3].
 Next it calculates the average difference for each index in the array using a loop that iterates through all five values in nums.
 The first iteration is done on index 0 which has two values: 2 and 5; so its average difference is |2 / 1 - (5 + 3 + 9 + 5 + 3) / 5| = |2 / 1 - 25 / 5| = |2 - 25| = 3.
 The second iteration is done on index 1 which has four values: (2+5), (3+9), (5+3), and (9+5); so its average difference is 7/4-20/4=|7/4-20/4|=||7/-40||=1.
 The third iteration is done on index 2 which has three values: (2+5+3) and (9+5+3); so its average difference is 10/6-17/6=
 The code computes the average difference of index 0, 1, and 2.
 The code first computes the average difference of index 0: |2 / 1 - (5 + 3 + 9 + 5 + 3) / 5| = |2 / 1 - 25 / 5| = |2 - 5| = 3.
 Next, it computes the average difference of index 1: |(2 + 5) / 2 - (3 + 9 + 5 + 3) / 4| = |7 / 2 - 20 / 4| = |3 - 5| = 2.
 Lastly, it computes the average difference of index 2: |(2 + 5 + 3) / 3 - (9 + 5 +
 The code is: def f(nums): print("The average difference of index {} is: {}".format(i, (nums[i] - nums[j]) / len(nums))) for i in range(len(nums)): if i == 0 or j == 0: return 0.0
 The code will return the minimum average difference of index 0.
 The average difference of index 1 is: |(2 + 5) / 2 - (5 + 3) / 1| = |15 / 2 - 7 / 1| = |3 - 3| = 0.
 - The average difference of index 2 is: |(2 + 5 + 3) / 3 - (5 + 3) / 2| = |18 / 3 - 8 / 2| = |4 - 4| = 0.
 - The average difference of index 3 is: |(2 + 5 + 9) / 4 - (5 + 9) / 6| = |19/4- 16/6=1.

*/