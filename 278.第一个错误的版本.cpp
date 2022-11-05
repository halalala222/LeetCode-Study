/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
bool isBadVersion(int version);

/*
 * 和我学的二分查找有点区别
*/
class Solution {
public:
    int firstBadVersion(int n) {
        int i = 1, j = n;
        while (i <= j) {
            // 向下取整除法计算中点 m 
            int m = i + (j - i) / 2;
            // 若 m 是错误版本，则最后一个正确版本一定在闭区间 [i, m - 1]
            if (isBadVersion(m)) j = m - 1;
            // 若 m 是正确版本，则首个错误版本一定在闭区间 [m + 1, j]
            else i = m + 1;
        }
        // i 指向首个错误版本，j 指向最后一个正确版本
        return i;
    }
};

// @lc code=end

