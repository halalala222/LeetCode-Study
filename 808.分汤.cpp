#include <math.h>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=808 lang=cpp
 *
 * [808] 分汤
 */

/**
 * md
 * 读题目读了半天，然后没思路，
 * 看了下题解，感觉好牛
 * woc理解错题目了，看错字了。是 A　和 B　各有　ｎ　毫升而不是共有，所以
 * 是将　A　和　B 都分配出去，看顺序
 * 对应的动态规划方程的含义是，当前 A B 剩余量可能是前一个剩余量进行四个操作而来，所以是进行四个操作
 * 的答案的 1/4
 * 一个从上到下的，即 dp[4][4] 出现的概率是由 1/4 dp[0][4] + 1 /4 dp[1][3] + 1 / 4 dp[2][2] + 1 / 4 dp[1][3] + 1 / 4 [0][4]相加组成
*/
// @lc code=start
class Solution {
public:
    double soupServings(int n) {
        n = ceil((double) n / 25);
        //这个可以避免很多时间，因为到某个时间之后A很大概率会B更先分配完
        if (n >= 179) {
            return 1.0;
        }
        //这里有提前预设值：当 A 没分配完 和 B 已经分配完的答案为 0 即默认的值
        vector<vector<double>> dp(n + 1, vector<double>(n + 1));
        //提前预设值，当 A　和　B　分配完的答案为　１／２
        dp[0][0] = 0.5;
        //提前预设边界值，当　A　分配完，B 还没有分配完的答案为 1
        for (int i = 1; i <= n; i++) {
            dp[0][i] = 1.0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = (dp[max(0, i - 4)][j] + dp[max(0, i - 3)][max(0, j - 1)] +
                           dp[max(0, i - 2)][max(0, j - 2)] + dp[max(0, i - 1)][max(0, j - 3)]) / 4.0;
            }
        }
        return dp[n][n];
    }
};
// @lc code=end

