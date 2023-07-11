/*
 * @lc app=leetcode.cn id=1911 lang=java
 *
 * [1911] 最大子序列交替和
 */
/**
 * 想不到，想不出来
 */
// @lc code=start
class Solution {
    public long maxAlternatingSum(int[] nums) {
        /**
         * 分两种情况，确实。如果最后一个元素的下标是否是奇偶对于子序列的计算是不一样的。
         * 觉得这题有一种数学题上的美感。
         */
        long f = 0, g = 0;
        for (int num : nums) {
            long ff = Math.max(g - num, f);
            long gg = Math.max(f + num, g);
            f = ff;
            g = gg;
        }
        return Math.max(f, g);
    }
}
// @lc code=end
