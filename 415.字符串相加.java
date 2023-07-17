/*
 * @lc app=leetcode.cn id=415 lang=java
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution {
    public String addStrings(String num1, String num2) {
        int nums1Index = num1.length() - 1, nums2Index = num2.length() - 1;
        var result = new StringBuffer("");
        /**
         * 这里的 add 是需要 > 0 的，这样子才能保证最后还有一位进一的时候，能够继续 append 字符串。
         */
        for (int add = 0; add > 0 || nums1Index >= 0 || nums2Index >= 0; nums1Index--, nums2Index--) {
            /**
             * 这下面需要特判进行 index < 0 的判断，因为是双指针，从后往前，如果是最短的数，其 index < 0。
             * 所以会出现数组越界，如果是 index < 0 的话，对应的数值就是 0 。
             */
            int num1Number = nums1Index < 0 ? 0 : num1.charAt(nums1Index) - '0'; // - '0' 转换为对应的真实数字
            int num2Number = nums2Index < 0 ? 0 : num2.charAt(nums2Index) - '0';
            result.append((num1Number + num2Number + add) % 10);
            add = (num1Number + num2Number + add) / 10;
        }
        return result.reverse().toString();
    }
}
// @lc code=end
