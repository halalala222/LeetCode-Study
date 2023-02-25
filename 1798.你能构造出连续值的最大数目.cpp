#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=1798 lang=cpp
 *
 * [1798] 你能构造出连续值的最大数目
 */
/**
 * 想不到，没有这个天赋
 * [0,9],这个范围内是连续的，再选择一个数 x ,[0+x,9+x]这个范围内也是连续的
 * 需要达成，加上一个数之后，有序数组长度有所增加则，[0,9] 和 [0+x,9+x] 需要有交集的部分，
 * 即 0 + x <= 0 ，即可，相反如果 0 + x > 9 ，则会导致断层。
 */
// @lc code=start
class Solution
{
public:
    int getMaximumConsecutive(vector<int> &coins)
    {
        sort(coins.begin(), coins.end());
        int maxNum = 0;
        for (auto coin : coins)
        {
            if (coin > maxNum + 1)
            // 为什么要 + 1呢，因为 maxNum 是有序整数组中的最大一个整数，即最后一位整数，但是需要的结果是整数数组的个数，即最大整数 + 1 则是。
            // 因为是从 0 开始的整数 
                return maxNum + 1;
            maxNum += coin;
        }
        return maxNum + 1;
    }
};
// @lc code=end
