/*
 * @lc app=leetcode.cn id=1017 lang=java
 *
 * [1017] 负二进制转换
 */

// @lc code=start
class Solution {
    public String baseNeg2(int n) {
        if (n == 0) {
            return "0";
        }
        String result = "";
        while (n != 0) {
            int num = n % (-2);
            result = Math.abs(num) + result;
            if (num >= 0) {
                n = n / (-2);
            } else {
                n = n / (-2) + 1;
            }
        }
        return result;
    }
}
// @lc code=end
