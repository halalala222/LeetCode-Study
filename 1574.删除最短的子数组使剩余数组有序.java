import java.util.Arrays;

import javax.imageio.ImageIO;

/*
 * @lc app=leetcode.cn id=1574 lang=java
 *
 * [1574] 删除最短的子数组使剩余数组有序
 */

/**
 * 这怎么做呢？如何保证删除的就是最小的。
 * 感觉可以从最大的数开始删除，然后如果达到最非递减的时候。
 * cv 了，太难了吧这也
 */
// @lc code=start
class Solution {
    public int findLengthOfShortestSubarray(int[] arr) {
        int n = arr.length, right = n - 1;
        while (right > 0 && arr[right - 1] <= arr[right])
            --right;
        if (right == 0) return 0; // arr 已经是非递减数组
        // 此时 arr[right-1] > arr[right]
        int ans = right; // 删除 0 到 right-1
        for (int left = 0; left == 0 || arr[left - 1] <= arr[left]; ++left) {
            while (right < n && arr[right] < arr[left])
                ++right;
            // 此时 arr[left] <= arr[right]，从 left+1 到 right-1 可以删除
            ans = Math.min(ans, right - left - 1);
        }
        return ans;
    }
}

// @lc code=end
