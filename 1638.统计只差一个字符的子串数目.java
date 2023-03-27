/*
 * @lc app=leetcode.cn id=1638 lang=java
 *
 * [1638] 统计只差一个字符的子串数目
 */

/**
 * 有点懵，想不到什么好的方法，都是一些不大行，感觉实现不了的。
 */
/**
 * 看了一下中心扩散法，感觉好叼，但我确实感觉应该是这样子的，不过这也是一种枚举
 */
// @lc code=start
class Solution {
    public int countSubstrings(String s, String t) {
        int sSize = s.length();
        int tSize = t.length();
        char[] sChars = s.toCharArray();
        char[] tChars = t.toCharArray();
        // start[i][j] 表示 以s[i]与t[j]开头，相同的字符串长度
        int[][] start = new int[sSize][tSize];
        // 而且是从后往前遍历得，如果是以 s[i] t[j] 开头的相同的字符串长度为 2，那么以 s[i - 1] t[j - 1] 开头的相同的字符串长度应该是
        // 2 + 1，
        // 因为 以 s[i - 1] t[j - 1] 开头会比以 s[i] t[j] 开头多出一个 s[i - 1] t[j - 1] 所以长度是 + 1，
        for (int i = sSize - 1; i >= 0; i--) {
            for (int j = tSize - 1; j >= 0; j--) {
                if (sChars[i] != tChars[j])
                    continue;
                /**
                 * 如果 i j 有一个是对应最后一个字符，那么此时以 s[i] t[j] 开头的，相同的字符串长度为 1
                 * 因为以 s[i] t[j] 得下一个元素是 s[i+1] t[j+1] 此时无法向后移动
                 */
                start[i][j] = i == sSize - 1 || j == tSize - 1 ? 1 : start[i + 1][j + 1] + 1;
            }
        }
        // end[i][j] 表示 以s[i]与t[j]结尾，相同的字符串长度
        int[][] end = new int[sSize][tSize];
        // 这里是从前往后遍历得，如果是以 s[i] t[j] 结尾的相同的字符串长度为 2 ，那么已 s[i + 1] t[j + 1]
        // 结尾的相同的字符串长度应该是
        // 2 + 1
        // 因为 以 s[i + 1] t[j + 1] 开头会比以 s[i] t[j] 结尾多出一个 s[i + 1] t[j + 1]
        for (int i = 0; i < sSize; i++) {
            for (int j = 0; j < tSize; j++) {
                if (sChars[i] != tChars[j])
                    continue;
                end[i][j] = i == 0 || j == 0 ? 1 : end[i - 1][j - 1] + 1;
            }
        }
        int result = 0;
        for (int i = 0; i < sSize; i++) {
            for (int j = 0; j < tSize; j++) {
                //要找到对应 i j 不同的，然后其余的以相同的字符填充
                if (sChars[i] == tChars[j])
                    continue;
                // 获得以 s[i - 1] t[j - 1] 结尾的相同的子字符串个数，如果其中 i j 有一个为 0 话，对应的值就为 0，因为此之前无元素了。
                int leftCount = i > 0 && j > 0 ? end[i - 1][j - 1] : 0;
                // 获得以 s[i + 1] t[j + 1] 开头的相同的子字符串个数，如果其中 i j 有一个达到了对应的最后一个元素，对应的值为 0，因为此后无元素了。
                int rightCount = i < sSize - 1 && j < tSize - 1 ? start[i + 1][j + 1] : 0;
                // 从 leftCount 中取出 0 1 ~ leftCount 的元素，即在左侧的相同的子字符串中从 0 不断向左移。可以得到 leftCount +
                // 1个可能，右侧同理。
                result += (leftCount + 1) * (rightCount + 1);
            }
        }
        return result;
    }
}
// @lc code=end
