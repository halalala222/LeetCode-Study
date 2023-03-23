import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
 * @lc app=leetcode.cn id=1630 lang=java
 *
 * [1630] 等差子数组
 */

// @lc code=start
class Solution {
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        int n = l.length;
        List<Boolean> result = new ArrayList<Boolean>();
        for (int i = 0; i < n; i++) {
            boolean isSame = true;
            int lIndex = l[i], rIndex = r[i];
            int[] numSlice = Arrays.copyOfRange(nums, lIndex, rIndex + 1);
            Arrays.sort(numSlice);
            if (numSlice.length == 1) {
                isSame = true;
                continue;
            }
            int increments = numSlice[1] - numSlice[0];
            for (int j = 2; j < numSlice.length; j++) {
                if (numSlice[j] - numSlice[j - 1] != increments) {
                    isSame = false;
                    break;
                }
            }
            result.add(isSame);
        }
        return result;
    }
}
// @lc code=end
