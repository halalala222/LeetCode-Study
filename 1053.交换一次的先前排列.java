/*
 * @lc app=leetcode.cn id=1053 lang=java
 *
 * [1053] 交换一次的先前排列
 */

/**
 * 从后往前遍历。
 * 54/54 cases passed (0 ms)
 * Your runtime beats 100 % of java submissions 。我测搞毛
 * Your memory usage beats 5.12 % of java submissions (43.2 MB)
 */
// @lc code=start
class Solution {
    public int[] prevPermOpt1(int[] arr) {
        int size = arr.length;
        for (int i = size - 2; i >= 0; i--) {
            int maxSmallerNum = 0, maxSmallerNumIndex = 0, currentNum = arr[i];
            for (int j = i + 1; j < size; j++) {
                if (maxSmallerNum < arr[j] && arr[j] < currentNum) {
                    maxSmallerNum = arr[j];
                    maxSmallerNumIndex = j;
                }
            }
            if (maxSmallerNum != 0) {
                arr[i] = maxSmallerNum;
                arr[maxSmallerNumIndex] = currentNum;
                break;
            }
        }
        return arr;
    }
}
// @lc code=end
