#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=2335 lang=cpp
 *
 * [2335] 装满杯子需要的最短总时长
 */

// @lc code=start
class Solution
{
public:
    int fillCups(vector<int> &amount)
    {
        int result;
        int coldAmount = amount.at(0), warmAmount = amount.at(1), hotAmount = amount.at(2), totalAmount = coldAmount + warmAmount + hotAmount;
        int maxAmount = max(coldAmount, max(warmAmount, hotAmount));
        if (totalAmount - maxAmount <= maxAmount)
        {
            result = maxAmount;
        }
        else
        {
            int remainAmount = totalAmount - maxAmount * 2;
            result =  remainAmount % 2 == 1?  maxAmount + remainAmount / 2 + 1 : maxAmount + remainAmount / 2;
        }
        return result;
    }
};
// @lc code=end
