#include <algorithm>
#include <stdio.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
 */

// @lc code=start
class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(n + 1);
        if (n <= 2)
        {
            if (n == 2)
            {
                return 1;
            }
            else
            {
                return n;
            }
        }
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i < n + 1; i++)
        {
            printf("i : %d\n",i);
            dp[i] = dp[i - 1] + dp [i - 2] + dp[i - 3];
        }
        return dp[n];
    }
};
// @lc code=end

