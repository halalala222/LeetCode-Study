#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        vector<int> dp(n + 1);
        if (n <= 1)
        {
            return n;
        }
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i < n + 1; i++)
        {
            dp[i] = dp[i - 1] + dp [i - 2];
        }
        return dp[n];
    }
};
// @lc code=end

