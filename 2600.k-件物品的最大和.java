/*
 * @lc app=leetcode.cn id=2600 lang=java
 *
 * [2600] K 件物品的最大和
 */

// @lc code=start
class MySolution {
    public int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int afterPickOne = k - numOnes;
        if (afterPickOne <= 0) {
            return k;
        }
        int afterPickZero = afterPickOne - numZeros;
        if (afterPickZero <= 0) {
            return numOnes;
        }
        return numOnes - afterPickZero;
    }
}

class Solution {
    public int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        return Math.min(k, numOnes) - Math.max(k - numOnes - numZeros, 0);
    }
}
// @lc code=end
