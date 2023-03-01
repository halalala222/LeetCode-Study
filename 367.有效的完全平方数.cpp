#include <stdio.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */
/**
 * 二分查找
 */
// @lc code=start
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int left = 0, right = num;
        while (left <= right)
        {
            int mid = (right - left) / 2 + left;
            // 平方会超出限制
            long square = (long)mid * mid;
            if (square < num) {
                left = mid + 1;
            } else if (square > num) {
                right = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
