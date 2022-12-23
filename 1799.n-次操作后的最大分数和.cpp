#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
/*
 * @lc app=leetcode.cn id=1799 lang=cpp
 *
 * [1799] N 次操作后的最大分数和
 */

// @lc code=start
class Solution
{
public:
    int maxScore(vector<int> &nums)
    {
        int m = nums.size();
        //左移 获取到一个状态数组
        vector<int> dp(1 << m, 0);
        //预先进行求出最大公约数
        vector<vector<int>> gcd_tmp(m, vector<int>(m, 0));
        for (int i = 0; i < m; ++i)
        {
            for (int j = i + 1; j < m; ++j)
            {
                gcd_tmp[i][j] = gcd(nums[i], nums[j]);
            }
        }        
        //状态数组的个数
        int all = 1 << m;
        //从 1 开始，因为 0 是初始状态，表示原始值
        for (int s = 1; s < all; ++s)
        {
            //__builtin_popcount()用于计算一个 32 位无符号整数有多少个位为1
            int t = __builtin_popcount(s);
            // t & 1 用于判断 s 是不是奇数，因为，如果最后一位为 1 的话，无论怎么样都会为 true
            if (t & 1)
            {
                continue;
            }
            for (int i = 0; i < m; ++i)
            {
                //判断 s 的二进制串是不是比 i 的二进制串大，即 s 是否 > i
                if ((s >> i) & 1)
                {
                    for (int j = i + 1; j < m; ++j)
                    {
                        if ((s >> j) & 1)
                        {
                            //这里异或 （1 << i）和 （1 << j）相当于在 s 的二进制串上第 i 位被选出（值为 0 ），j 同理
                            //为什么是 t / 2 表示是从n ...> 0 的一个逆序，而不是从 0 ...> n 的正序，对于将上一种状态下到达此状态
                            //max 对于不同顺序的枚举是没有任何影响
                            dp[s] = max(dp[s], dp[s ^ (1 << i) ^ (1 << j)] + t / 2 * gcd_tmp[i][j]);
                        }
                    }
                }
            }
        }
        return dp[all - 1];
    }
};

// @lc code=end
