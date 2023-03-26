import java.util.HashSet;

/*
 * @lc app=leetcode.cn id=2395 lang=java
 *
 * [2395] 和相等的子数组
 */

// @lc code=start
class Solution {
    public boolean findSubarrays(int[] nums) {
        HashSet<Integer> appearedSum = new HashSet<Integer>();
        for (int i = 1; i < nums.length; i++) {
            int sum = nums[i] + nums[i - 1];
            boolean isAppeared = appearedSum.contains(sum);
            if (isAppeared)
                return true;
            appearedSum.add(sum);
        }
        return false;
    }
}
// @lc code=end
