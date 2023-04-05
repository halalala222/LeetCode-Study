/*
 * @lc app=leetcode.cn id=2427 lang=java
 *
 * [2427] 公因子的数目
 */

// @lc code=start
class Solution {
    public int commonFactors(int a, int b) {
        int minNum = Math.min(a, b);
        int result = 0;
        for (int i = 1; i < minNum + 1; i++) {
            if (a % i == 0 && b % i == 0) {
                result++;
            }
        }
        return result;
    }
}
// @lc code=end
