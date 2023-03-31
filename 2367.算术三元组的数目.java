import java.util.HashSet;
import java.util.Set;

/*
 * @lc app=leetcode.cn id=2367 lang=java
 *
 * [2367] 算术三元组的数目
 */

// @lc code=start
class Solution1 {
    public int binarysearch(int[] nums, int num) {
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > num) {
                right = mid - 1;
            }
            if (nums[mid] < num) {
                left = mid + 1;
            }
            if (nums[mid] == num) {
                return mid;
            }
        }
        return -1;
    }

    public int arithmeticTriplets(int[] nums, int diff) {
        int result = 0;
        for (int num : nums) {
            int isFindedNext = binarysearch(nums, num + diff);
            int isFindedNextTheNext = binarysearch(nums, num + diff * 2);
            if (isFindedNext != -1 && isFindedNextTheNext != -1) {
                result++;
            }
        }
        return result;
    }
}

/**
 * 下面这个不用自己实现 find 了都。
 */
class Solution {
    public int arithmeticTriplets(int[] nums, int diff) {
        Set<Integer> theNums = new HashSet<Integer>();
        for (int num : nums) {
            theNums.add(num);
        }
        int result = 0;
        for (int num : nums) {
            if (theNums.contains(num + diff) && theNums.contains(num + diff * 2)) {
                result++;
            }
        }
        return result;
    }
}

// @lc code=end
