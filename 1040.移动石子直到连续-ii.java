import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=1040 lang=java
 *
 * [1040] 移动石子直到连续 II
 */
/**
 * 吊的，思维题，中等题，被薄杀了
 * https://leetcode.cn/problems/moving-stones-until-consecutive-ii/solution/jie-ti-si-lu-by-owenzzz/
 * 
 */
// @lc code=start
class Solution {
    public int[] numMovesStonesII(int[] stones) {
        Arrays.sort(stones);
        int size = stones.length;
        int max = stones[size - 1] - stones[0] + 1 - size;
        max -= Math.min(stones[1] - stones[0] - 1, stones[size - 1] - stones[size - 2] - 1);
        int min = max;
        int j = 0;
        // 通过窗口获得以 i 为左边界中距离为 size 中，具有的石头数
        // 当 i 固定是，不断地右移 j 然后之间的石头数就等于 j - i + 1
        // 如果 i 右移，此时没有改变的 j ，区间的距离一定也是满足条件的，所以需要再次不断地右移调整 j 的位置
        for (int i = 0; i < size; i++) {
            while (j + 1 < size && stones[j + 1] - stones[i] + 1 <= size) {
                ++j;
            }
            // j - i + 1 是 其中的石头数，size - (j - i + 1) 是需要挪动的石头数
            int count = size - (j - i + 1);
            // 特殊情况在 stondes[0] - stones[n-2] 的的石头是连续的，只存在对后的一个端点石头
            if (j - i + 1 == size - 1 && stones[j] - stones[i] + 1 == size - 1) {
                count = 2;
            }
            min = Math.min(min, count);
        }
        return new int[] { min, max };
    }
}
// @lc code=end
