
import java.util.HashSet;

/*
 * @lc app=leetcode.cn id=3 lang=java
 *
 * [3] 无重复字符的最长子串
 */
/**
 * 再战
 * 滑动窗口
 * 又不会了
 */
// @lc code=start
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        HashSet<Character> appearedChar = new HashSet<Character>();
        if (n == 0) {
            return 0;
        }
        // // int left = -1, right = 0, notRepeating = 0, result = 0;
        // // 感觉不用维护 notRepeating 因为 left 到 right 中维护的就是不重复的。
        // int left = -1, right = 0, result = 0;
        // while (right < n - 1) {
        // if (!appearedChar.contains(s.charAt(right + 1))) {
        // notRepeating += 1;
        // }
        // appearedChar.remove(s.charAt(++left));
        // notRepeating--;
        // result = Math.max(notRepeating, result);
        // }
        // return result;
        // 其实就是维护一个窗口，在以 left 为起点下，最大长度的无重复字符串，对应的 right 下标，当 left 移动的时候，不断向右移动 right
        // ，更新 right 获得新的 left 下最大最大的长度的无重复字符串
        int right = -1, result = 0;
        for (int left = 0; left < n; left++) {
            // 当 left = 0,&& right = -1 的时候表示没有开始
            if (left != 0) {
                // 移去最左侧的元素
                appearedChar.remove(s.charAt(left - 1));
            }
            // 如果 right + 1，即右边界还可以扩展没有达到最右边，并且 right 没有出现的话。
            while (right + 1 < n && !appearedChar.contains(s.charAt(right + 1))) {
                appearedChar.add(s.charAt(right + 1));
                right++;
            }
            result = Math.max(result, right - left + 1);
        }
        return result;
    }
}
// @lc code=end
