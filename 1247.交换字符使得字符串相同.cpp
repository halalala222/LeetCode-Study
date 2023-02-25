#include <string>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=1247 lang=cpp
 *
 * [1247] 交换字符使得字符串相同
 */

/**
 * 应该是一道找规律的题目
 * 如果不同处为奇数是无法进行调整相同的
 * 如果不同处为偶数，分为 1. 不同处都是相同的情况这样子，两个只需要一步即可相同，比如说 s1 中为 'x' s2 中为 'y', s1 中为 'x' s2 中为 'y'
 *                    2. 不同处不同的俩对，需要俩步
 * 70/70 cases passed (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 81.01 % of cpp submissions (6.1 MB)
 */
// @lc code=start
class Solution
{
public:
    int minimumSwap(string s1, string s2)
    {
        int len1 = s1.size(), len2 = s2.size();
        int num1 = 0, num2 = 0;
        if (len1 != len2)
            return -1;
        for (int i = 0; i < len1; i++)
        {
            if (s1.at(i) != s2.at(i))
            {
                s1.at(i) == 'x' ? num1 += 1 : num2 += 1;
            }
        }
        if ((num1 + num2) % 2) return -1;
        /**
         * 官方题解这里直接优化掉了，直接使用 % ，也是我就是想要一个余数，因为余数总是 0 1，这样子相加也并不影响结果
        */
        int result1 = num1 / 2, result2 = num2 / 2, left1 = num1 - result1 * 2, left2 = num2 - result2 * 2;
        return result1 + result2 + left1 + left2;
    }
};
// @lc code=end
