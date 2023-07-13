/*
 * @lc app=leetcode.cn id=931 lang=java
 *
 * [931] 下降路径最小和
 */

/**
 * 一个最简单的想法，
 * 遍历第一行的每一个元素，获得其得到的最小下降路径，然很取所有的最小下降路径的最小和
 */
// @lc code=start
class MySolution {
    public int oneMinFallingPathSum(int firstLineIndex, int[][] matrix) {
        int iIndex = firstLineIndex, pathSum = matrix[0][firstLineIndex];
        for (int j = 1; j < matrix[0].length; j++) {
            int leftIndex = iIndex - 1, belowIndex = iIndex, rightIndex = iIndex + 1;
            int leftValue = Integer.MAX_VALUE, rightValue = Integer.MAX_VALUE, belowValue = matrix[j][iIndex];
            if (leftIndex > 0) {
                leftValue = matrix[j][leftIndex];
            }
            if (rightIndex < matrix[0].length) {
                rightValue = matrix[j][rightIndex];
            }
            int minValue = 0;
            if (leftValue < belowValue) {
                if (rightValue < leftValue) {
                    iIndex = rightIndex;
                    minValue = rightValue;
                } else {
                    iIndex = leftIndex;
                    minValue = leftValue;
                }
            } else {
                if (rightValue < belowValue) {
                    iIndex = rightIndex;
                    minValue = rightValue;
                } else {
                    iIndex = belowIndex;
                    minValue = belowValue;
                }
            }
            pathSum += minValue;
        }
        return pathSum;
    }

    public int minFallingPathSum(int[][] matrix) {
        if (matrix.length == 0) {
            return 0;
        }
        int minPath = Integer.MAX_VALUE;
        for (int i = 0; i < matrix[0].length; i++) {
            minPath = Math.min(minPath, oneMinFallingPathSum(i, matrix));
        }
        return minPath;
    }
}

/**
 * 还是觉得要用动态规划，但是不是很会
 */

class Solution {
    public int minFallingPathSum(int[][] matrix) {
        // 是一个会不断变化的数组，
        // 表示当前行中到达对应的位置的最小 pathSum
        int[] pathSum = new int[matrix.length];
        for (var row : matrix) {
            var temp = pathSum.clone();
            for (int j = 0; j < row.length; j++) {
                if (j> 0) {
                    temp[j] = Math.min(temp[j], pathSum[j - 1]);
                }
                if (j + 1 < row.length) {
                    // 这里为什么是 temp[j] 而不是 pathSum[j]
                    // 因为在此之前有一次 j > 0 的判断，可以获取到 f[j],path[j - 1] 两者中的最小值
                    // 这个时候使用 temp[j] 的话就可以获取到 [f - 1] , f[j] ,path[j - 1] 三者中的最小值。
                    temp[j] = Math.min(temp[j], pathSum[j + 1]);
                }
                temp[j] += row[j];
            }
            pathSum = temp;
        }
        int minPathSum = Integer.MAX_VALUE;
        for (var pathSumNum : pathSum) {
            minPathSum = Math.min(minPathSum, pathSumNum);
        }
        return minPathSum;
    }
}
// @lc code=end
