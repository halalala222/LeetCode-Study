#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=1742 lang=cpp
 *
 * [1742] 盒子中小球的最大数量
 */

// @lc code=start
/**
 * 使用双循环暴力破解
 * 不够快以及不够优雅
 * 97/97 cases passed (40 ms)
 * Your runtime beats 19.65 % of cpp submissions
 * Your memory usage beats 6.11 % of cpp submissions (48.5 MB)
*/
/**
 * 对于数组的长度问题，我看题解有一个说不超过 45 好像时因为 hightLimit <= 1e5 这个时候
 * 最大值为 99999 之和为 45 所以 45 长即可
 * 调整完后有了显著提升
 * 97/97 cases passed (8 ms)
 * Your runtime beats 86.03 % of cpp submissions
 * Your memory usage beats 94.32 % of cpp submissions (5.7 MB)
 * 内存使用缩减了 10% 时间也提高了
*/
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int n = highLimit - lowLimit + 1;
        vector<int> results(46);
        int result = 0;
        for (int i = lowLimit; i < highLimit + 1            ; i++)
        {
            int temp  = 0;
            int num = i;
            while (num)
            {
                temp += num % 10;
                num /= 10;
            }
            results.at(temp)++;
            result = results.at(temp) > result ? results.at(temp) : result;
        }
        return result;
    }
};
// @lc code=end

