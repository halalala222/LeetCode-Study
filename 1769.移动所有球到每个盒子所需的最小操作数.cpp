#include <vector>
#include <string>
#include <stdio.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1769 lang=cpp
 *
 * [1769] 移动所有球到每个盒子所需的最小操作数
 */

/**
 * 尝试一下使用双循环，因为最小操作数的话，就是俩个位置之间的直线距离
 * 即 i - j 就可以了
 * 啊，这么没用含量？双循环也能过？md，是真辣鸡啊，这道题，不过是不是
 * 可能要想很好的做法的时候会比较难
*/
// @lc code=start
/**
 * 看了下官方题解，感觉挺好的，线性时间复杂度。
*/
class MySolution {
public:
    vector<int> minOperations(string boxes) {
        int length = boxes.length();
        vector<int> result(length,0);
        for (int i = 0; i < length; i++)
        {
            if (boxes.at(i) == '1')
            {
                for (int j = 0; j < length; j++)
                {
                    result.at(j) += abs(i - j);
                }   
            }
        }
        return result;
    }
};

/**
 * 准备复刻官方题解
 * 都是讲 0 的情况进行完成初始化后
*/
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int length = boxes.length();
        int operations = 0;
        // 这个 left 是用来后续初始化话的，因为后续循环
        // 是从下标 1 开始的，此时 left 的值 ＝ index = 0 时候的，值是不是1
        int left = boxes.at(0) - '0',right = 0;
        // 第一次循环，用于初始化第一个值，即 i = 0，第一个盒子的
        // 的值，因为，都是依据第一个盒子的操作数，进行推导出后一个盒子的
        // 的操作数。有点像动态规划
        // 下面的 left 表示在 i 是，i 左边有多少个 1，同理，right 表示 i 右边有多少个 1
        // do[i] 表示移动到 i 的最小操作数
        // dp[i] = dp[i - 1] + left - right;
        for (int i = 1; i < length; i++)
        {
            if (boxes.at(i) == '1')
            {
                right++;
                operations += i;
            }
        }
        vector<int> result(length);
        result.at(0) = operations;
        for (int i = 1; i < length; i++)
        {
            printf("left : %d,right : %d\n",left,right);
            operations += left - right;
            if (boxes.at(i) == '1')
            {
                left++;
                right--;
            }
            result.at(i) = operations;
        }
        return result;
    }
};
// @lc code=end

