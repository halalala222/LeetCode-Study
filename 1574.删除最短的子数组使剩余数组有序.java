
/*
 * @lc app=leetcode.cn id=1574 lang=java
 *
 * [1574] 删除最短的子数组使剩余数组有序
 */

/**
 * 这怎么做呢？如何保证删除的就是最小的。
 * 感觉可以从最大的数开始删除，然后如果达到最非递减的时候。
 * cv 了，太难了吧这也
 * 好像有一点懂了 最长非递减后缀 就是数组从后往前遍历得到一个顺序的最长的非递减数组，下面的 right 的初始化为对应数组的第一个元素下标
 *             最长非递减前缀 就是数组从前往后遍历得到一个顺序的最长的非递减数组。
 */
// @lc code=start
class Solution {
    public int findLengthOfShortestSubarray(int[] arr) {
        int n = arr.length, right = n - 1;
        while (right > 0 && arr[right - 1] <= arr[right])
            --right;
        if (right == 0) return 0; // arr 已经是非递减数组
        // 此时 arr[right-1] > arr[right]
        int ans = right; // 删除 0 到 right-1  (right - 1 + 1)
        /**
         * 上面的 ans 是没有缩小最长非递减后缀的左边范围得到的一个初始值，即最终不断增加 left 的值，缩短范围
         * 可以得到 final ans <= right(初始化的 right )
         */
        /**
         * left 从 0 开始不断增加缩短范围 (left,right) 为删除区间，从 0 开始不断的缩短删除区间。
         * 限制 left 是在最长非递减前缀区间内进行递增。arr[left - 1] <= arr[left]
         * 这是一个动态的过程，并不能保证一直递增到最后 (left,right) 是最小的。
         * 需要取得动态过程中的最小值
         */
        /**
         * 对于循环条件为什么不需要设置 left <= right，因为如果当 left = right 的时候，表示其中没有需要删除掉元素
         * 即已经是非递减数组了，这种情况在上述中已经判断过了。
         */
        for (int left = 0; left == 0 || arr[left - 1] <= arr[left]; ++left) {
            // 在 left 不断增加的时候，如果此时 left 的值 > 当前 right 的值，需要将 right 增加到
            // arr[right] > arr[left]
            // 这样才能维护 (left,right) 中是需要删除掉的值，其余的为非递减的。
            while (right < n && arr[right] < arr[left])
                ++right;
            // 此时 arr[left] <= arr[right]，从 left+1 到 right-1 可以删除
            ans = Math.min(ans, right - left - 1);
        }
        return ans;
    }
}

// @lc code=end
