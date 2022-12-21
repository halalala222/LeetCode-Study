#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1753 lang=cpp
 *
 * [1753] 移除石子的最大得分
 */

// @lc code=start
/**
 * 尽可能的让最大的数和第二大的数通过最小的数调整到最接近的时候
 * 如果具有俩个最大的数就直接返回
 * 最后卡在了
 * 24
 * 19
 * 24
 */
class Solution
{
public:
    int maximumScore(int a, int b, int c)
    {
        vector<int> scores = {a, b, c};
        sort(scores.begin(), scores.end());
        if (scores.at(1) == scores.at(2))
        {
            // 需要进行 + 最小的数 / 2
            return scores.at(1) + scores.at(0) / 2;
        }
        if (scores.at(0) + scores.at(1) >= scores.at(2))
        {
            /*
             * 将最大的和第二大的凑成差距最小的
             * 1. 最小的数 = 最大的数 - 第二大的数 return : 最大的数
             * 2. 最小的数 > 最大的数 - 第二大的数 return : 最大的数 + （最小的数 - （最大的数 - 第二大的数） ) / 2
             */
            return (scores.at(2) + ((scores.at(0) + scores.at(1) - scores.at(2)) / 2));
        }
        return scores.at(0) + scores.at(1);
    }
};
/**
 * 官方题解比我的题解更加优雅
 * 优雅很多
 * a <= b <= c
 * a + b < c，在这种情况下可以将 a 和 b 中的每一个石子与 c 中的配对。答案为 a + b。
 * a + b >= c,题解是以 c 为出发点，将 c 和 a b 中的数
 */
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int sum = a + b + c;
        int maxVal = max({a, b, c});
        if (sum - maxVal < maxVal) {
            return sum - maxVal;
        } else {
            return sum / 2;
        }
    }
};
// @lc code=end
