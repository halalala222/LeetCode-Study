import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=1000 lang=java
 *
 * [1000] 合并石头的最低成本
 * stones : 6446
 * 8
 * stones : 686
 * 14
 * stones : 146
 * 20
 * 并不是最少的那个，感觉有点动态规划的感觉。但是不大会
 * 又是前缀树，又是记忆和搜索，真难啊
 */

// @lc code=start
// class Solution {
//     private int[] currentStones;

//     public int merge(int k) {
//         int[] stones = currentStones;
//         System.out.print("stones : ");
//         int min = Integer.MAX_VALUE, minIndex = 0;
//         for (int i = 0; i < stones.length; i++) {
//             System.out.print(stones[i]);
//         }
//         System.out.println();
//         for (int i = 0; i + k <= stones.length; i++) {
//             int stonesCount = 0;
//             for (int j = 0; j < k; j++) {
//                 stonesCount += stones[i + j];
//             }
//             if (min > stonesCount) {
//                 minIndex = i;
//                 min = stonesCount;
//             }
//         }
//         System.out.println(min);
//         int[] newStones = new int[stones.length - (k - 1)];
//         int index = 0;
//         for (int i = 0; i < stones.length; i++, index++) {
//             if (i != minIndex) {
//                 newStones[index] = stones[i];
//             } else {
//                 i += (k - 1);
//                 newStones[index] = min;
//             }
//         }
//         currentStones = newStones;
//         return min == Integer.MAX_VALUE ? 0 : min;
//     }

//     public int mergeStones(int[] stones, int k) {
//         int size = stones.length;
//         // 无法合并
//         if ((size - 1) % (k - 1) != 0) {
//             return -1;
//         }
//         currentStones = stones;
//         int result = 0;
//         while (currentStones.length > 1) {
//             result += merge(k);
//         }
//         return result;
//     }
// }

class Solution {
    private int[][][] memo;
    private int[] s;
    private int k;

    public int mergeStones(int[] stones, int k) {
        int n = stones.length;
        if ((n - 1) % (k - 1) > 0) {
            return -1;
        }
        s = new int[n + 1];
        for (int i = 0; i < n; i++) {
            s[i + 1] = s[i] + stones[i];
        }
        this.k = k;
        memo = new int[n][n][k + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                memo[i][j] = new int[k + 1];
                Arrays.fill(memo[i][j], -1);
            }
        }
        return dfs(0, n - 1, 1);
    }

    public int dfs(int i, int j, int p) {
        if (memo[i][j][p] != -1)
            return memo[i][j][p];
        if (p == 1) {
            //这个是推导，把 i ~ j 合并成为 1 块 = 把 i ~ j 合并成 k 块，之后直接把这 k 块合并，
            return memo[i][j][p] = i == j ? 0 : dfs(i, j, k) + s[j + 1] - s[i];
        }
        int res = Integer.MAX_VALUE;
        // 这里将 m += (k - 1) 是因为，这样子才能把对应的 i , m 合成为 一堆
        for (int m = i; m < j; m += (k - 1)) {
            res = Math.min(res, dfs(i, m, 1) + dfs(m + 1, j, p - 1));
        }
        return memo[i][j][p] = res;
    }

}
// @lc code=end
