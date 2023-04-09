/*
 * @lc app=leetcode.cn id=2399 lang=java
 *
 * [2399] 检查相同字母间的距离
 */

// @lc code=start
class Solution {
    public boolean checkDistances(String s, int[] distance) {
        for (int i = 0; i < 26; i++) {
            int num = distance[i];
            int ASCII = 'a' + i;
            char currentChar = (char) ASCII;
            int index = s.indexOf(currentChar);
            if (index == -1) {
                continue;
            }
            int nextIndex = s.indexOf(currentChar, index + 1);
            if (nextIndex - index - 1 != num) {
                return false;
            }
        }
        return true;
    }
}
// @lc code=end
