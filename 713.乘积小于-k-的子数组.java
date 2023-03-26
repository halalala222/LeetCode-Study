
/*
 * @lc app=leetcode.cn id=713 lang=java
 *
 * [713] 乘积小于 K 的子数组
 */

/**
 * 第一想法就是暴力，我测暴力过了
 */
// @lc code=start
class Solution1 {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int size = nums.length, result = 0;
        for (int i = 0; i < size; i++) {
            int mul = 1;
            for (int j = i; j < size; j++) {
                mul *= nums[j];
                if (mul < k) {
                    ++result;
                } else {
                    break;
                }
            }
        }
        return result;
    }
}

/**
 * 双指针，left , right 一开始都为 0 ，然后不断的遍历 right ，知道遍历过程中
 * mul >= k，此时通过增加 left 使得 left & right 之间的范围减到不符合条件
 */
class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int size = nums.length, left = 0, right = 0, mul = 1, result = 0;
        while (right < size) {
            mul *= nums[right];
            while (mul >= k) {
                mul /= nums[left];
                left++;
            }
            result += right - left + 1;
            right++;
        }
        return result;
    }
}
// @lc code=end
