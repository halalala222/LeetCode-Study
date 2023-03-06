#include <vector>
#include <unordered_map>
#include <stdio.h>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 */

// @lc code=start
class DPSolution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        // unordered_map<int, int> pairss;
        // int minRight = INT_MAX, maxLeft = 0, minLeft = 0;
        // for (auto pair : pairs)
        // {
        //     minRight = min(pair.at(1), minRight);
        //     minLeft = minRight == pair.at(1) ? pair.at(0) : minLeft;
        //     maxLeft = max(pair.at(0), maxLeft);
        //     if (pairss.count(pair.at(0)))
        //         pairss[pair.at(0)] = min(pair.at(1), pairss[pair.at(0)]);
        //     else
        //         pairss[pair.at(0)] = pair.at(1);
        // }
        // printf("minLeft : %d,maxLeft : %d\n", minLeft, maxLeft);
        // int result = 0;
        // for (int i = minLeft; i <= maxLeft; i++)
        // {
        //     printf("i : %d", i);
        //     if (pairss.count(i))
        //     {
        //         result++;
        //         i = pairss[i];
        //         printf("i : %d", i);
        //     }
        // }
        // return result;
        /**
         * 竟然可以用动态规划，仔细一想好像确实是可以用动态规划的，当前的最大长度的值，等于满足条件的上一个的最大长度值 + 1
         * 隐藏条件是，如果当前并没前一个最大长度值的时候，该值需要为 1 即可，即所有初始值为 1
         */
        int size = pairs.size();
        /**
         * 二维数组竟然也可以进行排序，恐怖
         */
        sort(pairs.begin(), pairs.end());
        /**
         * 排序完的话，可以肯定的一个结果是，按照 left 元素增加
         */
        vector<int> dp(size, 1);
        /**
         * 这里也是很巧妙的，因为是按照 left 的数值增加，要使得 pair[i][0] > pair[j][1]
         * 只有可能在 < i 的元素里面。
         */
        for (int i = 1; i < size; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (pairs.at(i).at(0) > pairs.at(j).at(1))
                    dp.at(i) = max(dp.at(i), dp.at(j) + 1);
            }
        }
        return dp.at(size - 1);
        /**
         * 一直搞不懂动态规划，到时候看看那个刷题教程学一下
         */
    }
};
/**
 * 贪心的想法好叼我测
 * 要挑选最长数对链的第一个数对时，最优的选择是挑选第二个数字最小的，这样能给挑选后续的数对留下更多的空间。挑完第一个数对后，要挑第二个数对时，也是按照相同的思路，是在剩下的数对中，第一个数字满足题意的条件下，挑选第二个数字最小的。
 * 按照这样的思路，可以先将输入按照第二个数字排序，然后不停地判断第一个数字是否能满足大于前一个数对的第二个数字即可。
 */
class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {

        int current = INT_MIN, res = 0;
        /**
         * 这个得学习一下
         */
        sort(pairs.begin(), pairs.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });
        /**
         * 按照 right 大小排序后，通过直接遍历即可贪心到最终的结果
        */
        for (auto &pair : pairs)
        {
            /**
             * current 表示当前最长得链的 maxRight，如果遍历中存在 left > current 表示此时该元素可以接入到链中
             * 并更新 current 的值
            */
            if(current < pair[0])
            {
                res++;
                current = pair[1];
            }
        }
        return res;
    }
};
// @lc code=end
