#include <string>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=2379 lang=cpp
 *
 * [2379] 得到 K 个黑块的最少涂色次数
 */

// @lc code=start
/**
 * 本来想使用滑动窗口做的，但是做着做着发现不是滑动窗口了，窗口需要固定住，用两个指针的
 */
class Solution1
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int len = blocks.size();
        int minMum = INT_MAX;
        for (int i = 0; i + k - 1 < len; i++)
        {
            int currentMum = 0;
            for (int j = i; j < i + k; j++)
            {
                if (blocks.at(j) == 'W')
                {
                    currentMum++;
                    printf("j : %d", j);
                }
            }
            printf("\n");
            minMum = min(minMum, currentMum);
        }
        return minMum;
    }
};
/**
 * 尝试滑动窗口
 */
class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int left = 0, size = blocks.size(), right = k, wCount = 0, result = 0;
        for (int i = 0; i < k; i++)
        {
            if (blocks.at(i) == 'W')
                wCount++;
        }
        result = wCount;
        while (right < size)
        {
            if (blocks.at(right) == 'W')
                wCount++;
            if (blocks.at(left) == 'W')
                wCount--;
            ++right;
            ++left;
            result = min(result,wCount);
        }
        return result;
    }
};
// @lc code=end
