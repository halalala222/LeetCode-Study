#include <numeric>
#include <stdio.h>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=878 lang=cpp
 *
 * [878] 第 N 个神奇数字
 */
/**
 * 看了下题解，感觉挺牛的，
 * 二分查找用得也是挺牛的。
 * 题解的意思就是说一个函数 f(x) = x/a + x/b - x/c (c是最小公倍数)
 * 表示当 x 的时候有 f(x) 个能被 a 或 b 整除的数
 * 并且这是要随着 x 增加非递减函数。
 * 表示当 n = y，的时候可能会对应着多个 x ，这个时候最小的 x 就是，所求的神奇数字，
 * 因为神奇数字是一个边界点， f(< 神奇数字 的数字) < n 但是 f(> 神奇数字 的数字) >= n，而且
 * 神奇数字是 f(x) = n，中最小的数字，而刚好到达这个数字的时候 f(x) = n。 
 * 这个时候通过这个函数查找到神奇数字，使用二分法，边界值，左边界为 a b 最小值，右边界为 (a b 最小值) * n，因为第 n 个神奇数字肯定 <= (a b 最小值) * n
 * 这个二分应该不是找到一个具体的值，而是找到一个具体的边界值，
 * 
*/
// @lc code=start
class Solution {
public:
    const int MOD = 1e9 + 7;
    int nthMagicalNumber(int n, int a, int b) {
        long long l = min(a,b);
        long long r = (long long) min(a,b) * n;
        int c = lcm(a,b);
        while (l <= r)
        {
            long long mid = ( l + r ) / 2;
            long long cur = mid / a + mid / b - mid / c ;
            if (cur >= n) r = mid - 1;
            else l = mid + 1;
        }
        return (r+1) % MOD;
    }
};
// @lc code=end

