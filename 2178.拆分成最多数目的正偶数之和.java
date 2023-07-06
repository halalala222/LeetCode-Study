/*
 * @lc app=leetcode.cn id=2178 lang=java
 *
 * [2178] 拆分成最多数目的正偶数之和
 */

import java.util.ArrayList;
import java.util.List;

// @lc code=start
class Solution {
    public List<Long> maximumEvenSplit(long finalSum) {
        List<Long> res = new ArrayList<>();
        if (finalSum % 2 == 1) {
            return res;
        }
        /**
         * 贪心从 2 4 6 8 ... 向上递增，不断的加最终达到无法再次添加一个
         * 偶数的时候截至。
         * 并不断地将 finalSum 减少。
         */
        for (long i = 2; i <= finalSum; i += 2) {
            res.add(i);
            finalSum -= i;
        }
        /**
         * 此时，已经无法再添加一个偶数
         * 会存在 res 中数之和 <= finalSum 最终剩下来的数据。
         * 
         */
        res.add(res.remove(res.size() - 1) + finalSum);
        return res;
    }
}
// @lc code=end
