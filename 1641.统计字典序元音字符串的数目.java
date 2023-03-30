/*
 * @lc app=leetcode.cn id=1641 lang=java
 *
 * [1641] 统计字典序元音字符串的数目
 */

 /**
  * 我测，数学题的解法，没做出来
  */
// @lc code=start
class Solution {
    public int countVowelStrings(int n) {
        return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
    }
}
// @lc code=end

