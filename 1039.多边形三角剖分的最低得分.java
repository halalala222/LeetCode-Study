import java.util.Arrays;
/*
 * @lc app=leetcode.cn id=1039 lang=java
 *
 * [1039] 多边形三角剖分的最低得分
 */

/**
 * 看懂了，一开始确实也是想用动态规划得，但是不会
 */
/**
 * 这个方法好屌
 * https://leetcode.cn/problems/minimum-score-triangulation-of-polygon/solution/shi-pin-jiao-ni-yi-bu-bu-si-kao-dong-tai-aty6/
 */
// @lc code=start
class Solution {
    private int[] v;
    // 通过一个 memo 存储对应得数据，不用每次获取的时候都要再重新获取一次。
    private int[][] memo;

    public int minScoreTriangulation(int[] values) {
        // /**
        // * 找到最小的两个，然后和为最小的两个数 * 剩下的所有的数之和
        // */
        // Arrays.sort(values);
        // int smallest = values[0];
        // int secondSmallest = values[1];
        // int reuslt = 0, mul = smallest * secondSmallest;
        // for (int i = 2; i < values.length; i++) {
        // reuslt += mul * values[i];
        // }
        // return reuslt
        // int result1 = 0, result2 = 0, size = values.length;
        // if (size == 3) {
        // return values[0] * values[1] * values[2];
        // }
        // for (int i = 0; i < size; i++) {
        // int mul = values[i] * values[(i + 1) % size] + values[(i + 2) % size];
        // if ((i & 1) == 0) {
        // result1 += mul;
        // } else {
        // result2 += mul;
        // }
        // }
        // return Math.min(result2, result1);
        v = values;
        int size = values.length;
        memo = new int[size][size];
        for (int i = 0; i < size; i++) {
            Arrays.fill(memo[i], -1);
        }
        return dfs(0, size - 1);
    }

    private int dfs(int i, int j) {
        if (i + 1 == j)
            return 0;
        if (memo[i][j] != -1)
            return memo[i][j];
        int result = Integer.MAX_VALUE;
        for (int k = i + 1; k < j; k++) {
            result = Math.min(result, dfs(i, k) + dfs(k, j) + v[i] * v[j] * v[k]);
        }
        return memo[i][j] = result;
    }
}
// @lc code=end
