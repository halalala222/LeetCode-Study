/*
 * @lc app=leetcode.cn id=209 lang=java
 *
 * [209] 长度最小的子数组
 */

/**
 * 不断地移动左右指针找到动态的最小区间。
 * 先移动右指针（right）指导 sum > target 此时，[left - right) 比区间内是满足的，即是其中一种可能的值
 * 增大左指针（left）缩小范围，左指针（left）在不断缩小的过程中，不需要重复的将 left 从 0 开始。
 * 好屌这个方法
 */
// @lc code=start
class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int size = nums.length;
        int res = Integer.MAX_VALUE, right = 0, sum = 0, left = 0;
        while (right < size) {
            sum += nums[right++];
            while (sum >= target) {
                // [left,right) 的长度为 right - left;
                res = Math.min(res, right - left);
                System.out.println(res);
                sum -= nums[left++];
            }
        }
        // 如果最后都没有符合要求的话 res = INT_MAX 的
        return res == Integer.MAX_VALUE ? 0 : res;
    }
}
// @lc code=end
